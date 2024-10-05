class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> dp(n);

        for(int i = 0; i < n; i++) {
            if(!dq.empty() && i - dq.front() > k) {
                dq.pop_front();
            }
            if(dq.empty()) {
                dp[i] = nums[i];
            } else {
                dp[i] = nums[i] + dp[dq.front()];
            }
            while(!dq.empty() && dp[dq.back()] < dp[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return dp.back();
    }
};