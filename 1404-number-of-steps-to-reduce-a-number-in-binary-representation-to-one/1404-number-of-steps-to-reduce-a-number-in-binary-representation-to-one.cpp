class Solution {
public:
    int numSteps(string s) {
        int ret = 0;

        while(s.length() > 1) {
            if(s.back() == '0') {
                s.pop_back();
                ++ret;
            } else {
                while(!s.empty() && s.back() == '1') {
                    s.pop_back();
                    ++ret;
                }
                ++ret;
                if(s.empty()) {
                    break;
                }
                s.back() = '1';
            }
        }

        return ret;
    }
};