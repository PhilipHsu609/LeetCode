class Solution {
public:
    string toGoatLatin(string sentence) {
        string ret;
        int word_cnt = 1;
        int last_spc = -1;
        int n = sentence.size();

        for(int i = 0; i <= n; ++i) {
            if(i == n || sentence[i] == ' ') {
                string cur = sentence.substr(last_spc + 1, i - last_spc - 1);
                string goat;

                if(isVowel(tolower(sentence[last_spc + 1]))) {
                    goat = cur + "ma";
                } else {
                    goat = cur.substr(1) + sentence[last_spc + 1] + "ma";
                }

                goat += string(word_cnt, 'a');
                ret += goat + " ";

                ++word_cnt;
                last_spc = i;
            }
        }

        ret.pop_back();
        return ret;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};