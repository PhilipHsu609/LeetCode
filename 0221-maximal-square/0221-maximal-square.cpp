class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ret = 0;
        vector<vector<int>> dp(m, vector<int>(n));

        for(int j = 0; j < n; ++j) {
            dp[0][j] = static_cast<int>(matrix[0][j] == '1');
            ret = max(ret, dp[0][j]);
        }

        for(int i = 1; i < m; ++i) {
            dp[i][0] = static_cast<int>(matrix[i][0] == '1');
            ret = max(ret, dp[i][0]);
            for(int j = 1; j < n; ++j) {
                if(matrix[i][j] == '0') {
                    continue;
                }

                int w = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                dp[i][j] = w + 1;
                ret = max(ret, dp[i][j]);
            }
        }

        return ret * ret;
    }
};