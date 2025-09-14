class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> cap, vow;

        for(const auto &w : wordlist) {
            cap.insert({str_tolower(w), w});
            vow.insert({str_devowel(w), w});
        }

        vector<string> ret;
        for(const auto &q : queries) {
            if(words.find(q) != words.end()) {
                ret.push_back(q);
            } else if(cap.find(str_tolower(q)) != cap.end()) {
                ret.push_back(cap[str_tolower(q)]);
            } else if(vow.find(str_devowel(q)) != vow.end()) {
                ret.push_back(vow[str_devowel(q)]);
            } else {
                ret.push_back("");
            }
        }

        return ret;
    }

    string str_tolower(string s) {
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return tolower(c);
        });
        return s;
    }

    string str_devowel(string s) {
        transform(s.begin(), s.end(), s.begin(), [](unsigned char ch) -> char {
            char c = tolower(ch);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                return '#';
            }
            return c;
        });
        return s;
    }
};