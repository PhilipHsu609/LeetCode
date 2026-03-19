class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ret = 0;

        vector<vector<array<int, 2>>> preSum(m + 1, vector<array<int, 2>>(n + 1)); // {xcnt, ycnt}
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int incIdx = -1;
                if(grid[i][j] == 'X') {
                    incIdx = 0;
                } else if(grid[i][j] == 'Y') {
                    incIdx = 1;
                }

                if(incIdx == -1) {
                    preSum[i + 1][j + 1][0] += preSum[i][j + 1][0] + preSum[i + 1][j][0] - preSum[i][j][0];
                    preSum[i + 1][j + 1][1] += preSum[i][j + 1][1] + preSum[i + 1][j][1] - preSum[i][j][1];
                } else {
                    preSum[i + 1][j + 1][incIdx] += preSum[i][j + 1][incIdx] + preSum[i + 1][j][incIdx] - preSum[i][j][incIdx] + 1;
                    preSum[i + 1][j + 1][incIdx ^ 1] += preSum[i][j + 1][incIdx ^ 1] + preSum[i + 1][j][incIdx ^ 1] - preSum[i][j][incIdx ^ 1];
                }

                if(preSum[i + 1][j + 1][0] != 0 && preSum[i + 1][j + 1][0] == preSum[i + 1][j + 1][1]) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};