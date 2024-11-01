class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string ret;

        for(int i = 0; i < n; i++) {
            int m = ret.length();
            if(m >= 2 && s[i] == ret[m - 1] && s[i] == ret[m - 2]) {
                continue;
            }
            ret += s[i];
        }

        return ret;
    }
};