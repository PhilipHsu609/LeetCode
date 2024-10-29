class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        for(int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        int ret = 0;
        for(int j = 1; j < n; j++) {
            bool stop = true;
            for(int i = 0; i < m; i++) {
                if(i > 0 && dp[i - 1][j - 1] > 0 && grid[i][j] > grid[i - 1][j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                    stop = false;
                }
                if(dp[i][j - 1] > 0 && grid[i][j] > grid[i][j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
                    stop = false;
                }
                if(i < m - 1 && dp[i + 1][j - 1] > 0 && grid[i][j] > grid[i + 1][j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
                    stop = false;
                }

                ret = max(ret, dp[i][j] - 1);
            }

            if(stop) {
                break;
            }
        }

        return ret;
    }
};