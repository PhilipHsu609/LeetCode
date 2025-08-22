class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int minx = n, miny = m, maxx = -1, maxy = -1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    continue;
                }

                minx = min(minx, j);
                miny = min(miny, i);
                maxx = max(maxx, j);
                maxy = max(maxy, i);
            }
        }

        return (maxx - minx + 1) * (maxy - miny + 1);
    }
};