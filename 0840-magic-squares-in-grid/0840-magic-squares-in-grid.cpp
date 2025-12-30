class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int ret = 0;
        for(int i = 0; i < m - 2; ++i) {
            for(int j = 0; j < n - 2; ++j) {
                if(isMagic(grid, i, j)) {
                    ++ret;
                }
            }
        }

        return ret;
    }

    bool isMagic(const vector<vector<int>> &grid, int i, int j) {
        int mask = 0;
        int row_sum[3] = {};
        int col_sum[3] = {};

        for(int r = 0; r < 3; ++r) {
            for(int c = 0; c < 3; ++c) {
                col_sum[r] += grid[i + r][j + c];
                row_sum[c] += grid[i + r][j + c];

                if((mask & (1 << grid[i + r][j + c])) != 0) {
                    return false;
                }

                mask |= 1 << grid[i + r][j + c];
            }
        }

        if(mask != (1 << 10) - 2) {
            return false;
        }

        int diag1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        int diag2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];

        if(diag1 != 15 || diag2 != 15) {
            return false;
        }

        for(int k = 0; k < 3; ++k) {
            if(row_sum[k] != 15 || col_sum[k] != 15) {
                return false;
            }
        }

        return true;
    }
};