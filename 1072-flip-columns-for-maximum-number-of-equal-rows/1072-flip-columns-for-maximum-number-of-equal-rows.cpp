class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<string, int> count;

        for(int i = 0; i < m; i++) {
            string row(n, '0');
            string irow(n, '1');
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1) {
                    row[j] = '1';
                    irow[j] = '0';
                }
            }
            count[row]++;
            count[irow]++;
        }

        int ret = 1;
        for(auto &[row, cnt] : count) {
            ret = max(ret, cnt);
        }

        return ret;
    }
};