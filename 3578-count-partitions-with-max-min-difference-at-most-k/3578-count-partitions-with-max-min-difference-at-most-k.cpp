class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        int MOD = 1e9 + 7;
        vector<int> dp(n + 1);
        vector<int> prefix(n + 2);
        deque<int> maxq, minq;

        dp[0] = 1;
        prefix[1] = 1;

        for(int i = 1, j = 0; i <= n; i++) {
            // update maxq
            while(!maxq.empty() && nums[maxq.back()] <= nums[i - 1]) {
                maxq.pop_back();
            }
            maxq.push_back(i - 1);
            //update minq
            while(!minq.empty() && nums[minq.back()] >= nums[i - 1]) {
                minq.pop_back();
            }
            minq.push_back(i - 1);

            // adjust the sliding window
            while(!maxq.empty() && !minq.empty() && nums[maxq.front()] - nums[minq.front()] > k) {
                if(maxq.front() == j) {
                    maxq.pop_front();
                }
                if(minq.front() == j) {
                    minq.pop_front();
                }
                j++;
            }

            dp[i] = (prefix[i] - prefix[j] + MOD) % MOD;
            prefix[i + 1] =  (prefix[i] + dp[i]) % MOD;
        }

        return dp[n];
    }
};

/*
    dp[i + 1] := #partitions for nums[0...i]
    dp[0] := 1 (base case)

    recurrence relation:
        dp[i + 1] = dp[j] + ... + dp[i] where nums[j...i] is a valid segment
    => prefix sum
    
    if nums[j...i] is a valid segment then for each j < m <= i, nums[m...i] is also a valid segment
    => sliding window to track the starting index j
    => monotonic decreasing queue to track the maximums
    => monotonic increasing queue to track the minimums
*/