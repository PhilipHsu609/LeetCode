class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        int ret = 0;
        unordered_map<char, int> lw, up;

        for(int i = 0; i < n; ++i) {
            if(islower(word[i])) {
                lw[word[i]] = i;
            } else {
                if(up.find(word[i]) == up.end()) {
                    up[word[i]] = i;
                }
            }
        }

        for(auto [c, i] : up) {
            if(lw.find(tolower(c)) == lw.end()) {
                continue;
            }
            if(up[c] > lw[tolower(c)]) {
                ++ret;
            }
        }

        return ret;
    }
};