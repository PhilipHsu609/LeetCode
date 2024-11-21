class Solution {
public:
    vector<int> dirs{0, 1, 0, -1, 0};

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n));

        for(const auto &g : guards) {
            grid[g[0]][g[1]] = 2;
        }

        for(const auto &w : walls) {
            grid[w[0]][w[1]] = 3;
        }

        for(const auto &g : guards) {
            dfs(grid, g[0], g[1]);
        }

        int ret = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    ret++;
                }
            }
        }

        return ret;
    }

    void dfs(vector<vector<int>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();

        for(int d = 0; d < 4; d++) {
            int ii = i + dirs[d], jj = j + dirs[d + 1];

            while(ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj] < 2) {
                grid[ii][jj] = 1;
                ii += dirs[d];
                jj += dirs[d + 1];
            }
        }
    }
};