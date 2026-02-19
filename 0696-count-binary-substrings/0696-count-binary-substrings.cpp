class Solution {
public:
    int countBinarySubstrings(string s) {
        int ret = 0;
        int ccnt = 1;
        int pcnt = 0;
        int n = s.length();

        for(int i = 1; i < n; ++i) {
            if(s[i - 1] == s[i]) {
                ++ccnt;
            } else {
                pcnt = ccnt;
                ccnt = 1;
            }

            if(ccnt <= pcnt) {
                ++ret;
            }
        }

        return ret;
    }
};