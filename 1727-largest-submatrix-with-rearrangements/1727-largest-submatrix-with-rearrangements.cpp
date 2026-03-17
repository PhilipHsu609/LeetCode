class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> ones(m, vector<int>(n));
        ones[0] = matrix[0];
        for(int i = 1; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 1) {
                    ones[i][j] = ones[i - 1][j] + 1;
                }
            }
        }

        int ret = 0;
        for(int i = 0; i < m; ++i) {
            map<int, int> freq;
            for(int j = 0; j < n; ++j) {
                ++freq[ones[i][j]];
            }

            int cnt = 0;
            for(auto it = freq.rbegin(); it != freq.rend() && it->first != 0; ++it) {
                cnt += it->second;
                ret = max(ret, it->first * cnt);
            }
        }

        return ret;
    }
};