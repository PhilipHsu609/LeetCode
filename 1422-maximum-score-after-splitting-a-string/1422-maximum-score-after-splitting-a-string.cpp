class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int ones = 0;
        for(char c : s) {
            if(c == '1') {
                ones++;
            }
        }

        int ret = 0;
        int zeros = 0;
        s.pop_back();
        for(char c : s) {
            if(c == '1') {
                ones--;
            }
            if(c == '0') {
                zeros++;
            }
            ret = max(ret, ones + zeros);
        }

        return ret;
    }
};