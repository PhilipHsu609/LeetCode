class Solution {
public:
    vector<int> dirs{0, 1, 0, -1, 0};

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int ret = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ret++;
                }
            }
        }

        return ret;
    }

    void dfs(vector<vector<char>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();

        if(i < 0 || j < 0 || i == m || j == n || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';
        for(int d = 0; d < 4; d++) {
            dfs(grid, i + dirs[d], j + dirs[d + 1]);
        }
    }
};