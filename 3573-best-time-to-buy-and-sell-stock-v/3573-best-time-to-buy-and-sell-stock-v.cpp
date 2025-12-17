class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        long long ret = 0;
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k + 1, vector<long long>(3, INT_MIN)));

        for(int j = 0; j <= k; ++j) {
            dp[0][j][0] = 0;
        }

        dp[0][1][1] = -prices[0];
        dp[0][1][2] = prices[0];

        for(int i = 1; i < n; ++i) {
            dp[i][0][0] = 0;
            for(int j = 1; j <= k; ++j) {
                dp[i][j][0] = max({dp[i - 1][j][0], dp[i - 1][j][1] + prices[i], dp[i - 1][j][2] - prices[i]});
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][0] + prices[i]);
                ret = max(ret, dp[i][j][0]);
            }
        }

        return ret;
    }
};