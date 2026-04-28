class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();

        int MOD = grid[0][0] % x;
        vector<int> vals;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] % x != MOD) {
                    return -1;
                }
                grid[i][j] /= x;
                vals.push_back(grid[i][j]);
            }
        }

        sort(vals.begin(), vals.end());

        int ret = 0;
        int target = vals[vals.size() / 2];
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                ret += abs(grid[i][j] - target);
            }
        }

        return ret;
    }
};