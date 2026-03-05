class Solution {
public:
    int minOperations(string s) {
        int ret0 = 0, ret1 = 0;
        int n = s.length();

        for(int i = 0; i < n; ++i) {
            if(i % 2 == 0) {
                ret0 += s[i] == '1';
                ret1 += s[i] == '0';
            } else {
                ret0 += s[i] == '0';
                ret1 += s[i] == '1';
            }
        }
        return min(ret0, ret1);
    }
};