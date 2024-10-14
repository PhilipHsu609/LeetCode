class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));

        for(int i = n; i >= 1; i--) {
            for(int j = i; j <= n; j++) {
                for(int k = i; k <= j; k++) {
                    int lb = (i > 1) ? nums[i - 2] : 1;
                    int rb = (j < n) ? nums[j] : 1;
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + lb * nums[k - 1] * rb);
                }
            }
        }

        return dp[1][n];
    }
};