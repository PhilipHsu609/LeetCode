class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ret(n, vector<char>(m, '.'));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ret[j][m - i - 1] = box[i][j];
            }
        }

        for(int j = 0; j < m; j++) {
            int k = n - 1;
            for(int i = n - 1; i >= 0; i--) {
                if(ret[i][j] == '*') {
                    k = i - 1;
                }
                if(ret[i][j] == '#') {
                    ret[i][j] = '.';
                    ret[k][j] = '#';
                    k--;
                }
            }
        }

        return ret;
    }
};