class Solution {
public:
    vector<vector<int>> memo;

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memo.resize(m, vector<int>(n, -1));

        int ret = 0;
        for(int i = 0; i < m; i++) {
            ret = max(ret, dfs(grid, i, 0));
        }

        return ret;
    }

    int dfs(vector<vector<int>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();

        if(j == n - 1) {
            return 0;
        }

        if(memo[i][j] != -1) {
            return memo[i][j];
        }

        int ret = 0;
        if(i > 0 && grid[i][j] < grid[i - 1][j + 1]) {
            ret = max(ret, dfs(grid, i - 1, j + 1) + 1);
        }

        if(grid[i][j] < grid[i][j + 1]) {
            ret = max(ret, dfs(grid, i, j + 1) + 1);
        }

        if(i < m - 1 && grid[i][j] < grid[i + 1][j + 1]) {
            ret = max(ret, dfs(grid, i + 1, j + 1) + 1);
        }

        return memo[i][j] = ret;
    }
};