class Solution {
public:
    string makeLargestSpecial(string s) {
        if(s.length() <= 1) {
            return s;
        }

        int cnt = 0;
        int start = 0;
        vector<string> subspecial;

        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '1') {
                ++cnt;
            } else {
                --cnt;
            }

            if(cnt == 0) {
                string sub = s.substr(start + 1, i - start - 1);
                subspecial.push_back("1" + makeLargestSpecial(sub) + "0");
                start = i + 1;
            }
        }

        sort(subspecial.begin(), subspecial.end(), greater<>());
        string ret;
        for(const auto &sub : subspecial) {
            ret += sub;
        }

        return ret;
    }
};