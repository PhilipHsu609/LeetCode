class Solution {
public:
    bool checkRecord(string s) {
        int a = 0;
        int l = 0;
        int maxl = 0;
        for(char c : s) {
            if(c == 'L') {
                ++l;
                maxl = max(maxl, l);
                continue;
            }
            if(c == 'A') {
                ++a;
            }
            l = 0;
        }
        return a < 2 && maxl < 3;
    }
};