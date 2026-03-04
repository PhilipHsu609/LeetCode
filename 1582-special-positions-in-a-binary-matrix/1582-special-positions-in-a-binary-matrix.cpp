class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<int> row(m + 1), col(n + 1);

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                row[i] += mat[i - 1][j - 1];
                col[j] += mat[i - 1][j - 1];
            }
        }

        int ret = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(mat[i][j] == 1 && row[i + 1] == 1 && col[j + 1] == 1) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};