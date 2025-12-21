class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ret = 0;
        vector<bool> sorted(n - 1);

        for(int j = 0; j < m; ++j) {
            bool violate = false;
            for(int i = 0; i < n - 1; ++i) {
                if(sorted[i]) {
                    // strs[i] and strs[i + 1] are already sorted
                    continue;
                }

                if(strs[i][j] > strs[i + 1][j]) {
                    // we must delete this column
                    violate = true;
                }
            }

            if(!violate) {
                // update sorted
                for(int i = 0; i < n - 1; ++i) {
                    if(strs[i][j] < strs[i + 1][j]) {
                        sorted[i] = true;
                    }
                }
            } else {
                ++ret;
            }
        }

        return ret;
    }
};