class Solution {
public:
    string processStr(string s) {
        string ret;
        for(char ch : s) {
            if(ch == '*') {
                if(!ret.empty()) {
                    ret.pop_back();
                }
            } else if(ch == '#') {
                ret += ret;
            } else if(ch == '%') {
                ranges::reverse(ret);
            } else {
                ret += ch;
            }
        }
        return ret;
    }
};