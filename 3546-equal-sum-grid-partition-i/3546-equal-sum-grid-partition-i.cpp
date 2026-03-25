class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long total = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                total += grid[i][j];
            }
        }

        long long rowsum = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                rowsum += grid[i][j];
            }
            if(rowsum == total - rowsum) {
                return true;
            }
        }

        long long colsum = 0;
        for(int j = 0; j < n; ++j) {
            for(int i = 0; i < m; ++i) {
                colsum += grid[i][j];
            }
            if(colsum == total - colsum) {
                return true;
            }
        }

        return false;
    }
};