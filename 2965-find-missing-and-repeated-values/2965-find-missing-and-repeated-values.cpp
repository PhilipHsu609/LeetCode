class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 1;
        int diff = 0;
        int a = 0;
        unordered_set<int> s;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                diff += cnt - grid[i][j];
                cnt++;
                if(a == 0 && s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                }
                s.insert(grid[i][j]);
            }
        }

        return {a, diff + a};
    }
};