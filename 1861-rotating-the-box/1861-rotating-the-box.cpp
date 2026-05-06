class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();

        vector<int> cnt(m);
        unordered_map<int, int> pat;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(boxGrid[i][j] == '#') {
                    ++cnt[i];
                }

                if(boxGrid[i][j] == '*') {
                    pat[i * n + j] = cnt[i];
                    cnt[i] = 0;
                }
            }
        }

        vector<vector<char>> ret(n, vector<char>(m, '.'));

        for(int i = n - 1; i >= 0; --i) {
            for(int j = m - 1; j >= 0; --j) {
                if(boxGrid[m - j - 1][i] == '*') {
                    ret[i][j] = '*';
                    cnt[m - j - 1] = pat[(m - j - 1) * n + i];
                    continue;
                }

                if(cnt[m - j - 1] > 0) {
                    ret[i][j] = '#';
                    --cnt[m - j - 1];
                }
            }
        }

        return ret;
    }
};