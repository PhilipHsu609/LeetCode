class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> cols(n), rows(m);

        unordered_map<int, array<int, 2>> mp;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }

        for(int i = 0; i < m * n; i++) {
            auto [r, c] = mp[arr[i]];

            if(++rows[r] == n) {
                return i;
            }

            if(++cols[c] == m) {
                return i;
            }
        }

        return -1;
    }
};