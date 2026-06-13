class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        set<pair<int, int>> dp;
        for(int i = 0; i < n; ++i) {
            dp.insert({grid[0][i], i});
        }

        for(int i = 1; i < n; ++i) {
            set<pair<int, int>> ndp;
            for(int j = 0; j < n; ++j) {
                auto it = dp.begin();

                if(it->second == j) {
                    it = next(it);
                }

                ndp.insert({grid[i][j] + it->first, j});
            }
            dp = ndp;
        }

        return dp.begin()->first;
    }
};