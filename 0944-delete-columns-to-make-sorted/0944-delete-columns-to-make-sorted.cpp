class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ret = 0;

        string &cur = strs[0];
        for(const auto &s : strs) {
            for(int i = 0; i < m; ++i) {
                if(cur[i] > s[i]) {
                    if(cur[i] != 'z' + 1) {
                        cur[i] = 'z' + 1;
                        ++ret;
                    }
                } else {
                    cur[i] = s[i];
                }
            }
        }

        return ret;
    }
};