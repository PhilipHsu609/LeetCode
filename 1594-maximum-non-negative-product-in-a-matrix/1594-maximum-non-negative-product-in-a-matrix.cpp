class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int MOD = 1e9 + 7;
        vector<array<long long, 2>> dp(n);

        dp[0] = {grid[0][0], grid[0][0]};
        for(int j = 1; j < n; ++j) {
            dp[j][0] = max(dp[j - 1][0] * grid[0][j], dp[j - 1][1] * grid[0][j]);
            dp[j][1] = min(dp[j - 1][0] * grid[0][j], dp[j - 1][1] * grid[0][j]);
        }

        for(int i = 1; i < m; ++i) {
            vector<array<long long, 2>> ndp(dp);
            for(int j = 0; j < n; ++j) {
                ndp[j][0] = max(dp[j][0] * grid[i][j], dp[j][1] * grid[i][j]);
                ndp[j][1] = min(dp[j][0] * grid[i][j], dp[j][1] * grid[i][j]);

                if(j > 0) {
                    ndp[j][0] = max({ndp[j][0], ndp[j - 1][0] * grid[i][j], ndp[j - 1][1] * grid[i][j]});
                    ndp[j][1] = min({ndp[j][1], ndp[j - 1][0] * grid[i][j], ndp[j - 1][1] * grid[i][j]});
                }
            }
            dp = ndp;
        }

        return dp.back()[0] < 0 ? -1 : dp.back()[0] % MOD;
    }
};