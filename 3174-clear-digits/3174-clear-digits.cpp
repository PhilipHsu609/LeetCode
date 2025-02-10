class Solution {
public:
    string clearDigits(string s) {
        string ret;

        for(char c : s) {
            if(!ret.empty() && isalpha(ret.back()) && isdigit(c)) {
                ret.pop_back();
            } else {
                ret.push_back(c);
            }
        }

        return ret;
    }
};