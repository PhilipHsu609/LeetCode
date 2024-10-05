class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int ret = INT_MIN;
        vector<int> dp(n);
        deque<int> dq;

        for(int i = 0; i < n; i++) {
            if(!dq.empty() && i - dq.front() > k) {
                dq.pop_front();
            }

            if(dq.empty()) {
                dp[i] = nums[i];
            } else {
                dp[i] = max(nums[i], nums[i] + dp[dq.front()]);
            }

            ret = max(ret, dp[i]);
            while(!dq.empty() && dp[dq.back()] < dp[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return ret;
    }
};