class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int j = n - 1;
        int ret = 0;
        for(int i = 0; i < m; ++i) {
            while(j >= 0 && grid[i][j] < 0) {
                --j;
            }
            ret += n - 1 - j;
        }
        return ret;
    }
};