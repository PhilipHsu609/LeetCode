class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long ret = LLONG_MIN;

        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(4, -1e18));

        dp[0][0] = nums[0];
        for(int i = 1; i < n; ++i) {
            dp[i][0] = nums[i];

            if(nums[i - 1] < nums[i]) {
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) + nums[i];
            }
            if(nums[i - 1] > nums[i]) {
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]) + nums[i];
            }
            if(nums[i - 1] < nums[i]) {
                dp[i][3] = max(dp[i - 1][3], dp[i - 1][2]) + nums[i];
            }

            ret = max(ret, dp[i][3]);
        }

        return ret;
    }
};