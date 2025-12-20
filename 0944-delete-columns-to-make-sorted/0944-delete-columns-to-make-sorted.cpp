class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ret = 0;

        string cur = string(m, 'a' - 1);
        for(const auto &s : strs) {
            for(int i = 0; i < m; ++i) {
                cur[i] = (cur[i] > s[i]) ? 'z' + 1 : s[i];
            }
        }

        for(int i = 0; i < m; ++i) {
            if(cur[i] == 'z' + 1) {
                ++ret;
            }
        }

        return ret;
    }
};