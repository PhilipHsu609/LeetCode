class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length(), n = goal.length();

        if(m != n) {
            return false;
        }

        s += s;
        m += m;

        for(int i = 0; i < m - n; i++) {
            if(s.substr(i, n) == goal) {
                return true;
            }
        }

        return false;
    }
};