class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();

        if(k % n == 0) {
            return true;
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i % 2 == 0) {
                    int jj = ((j - k) % n + n) % n;
                    if(mat[i][j] != mat[i][jj]) {
                        return false;
                    }
                } else {
                    int jj = (j + k) % n;
                    if(mat[i][j] != mat[i][jj]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};