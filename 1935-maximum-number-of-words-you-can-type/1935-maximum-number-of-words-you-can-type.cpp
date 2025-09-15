class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        text += ' ';

        unordered_set<char> letters(brokenLetters.begin(), brokenLetters.end());

        int ret = 0;
        bool canType = true;
        int n = text.length();
        
        for(int i = 0; i < n; i++) {
            if(text[i] == ' ') {
                ret += static_cast<int>(canType);
                canType = true;
                continue;
            }

            if(letters.find(text[i]) != letters.end()) {
                canType = false;
            }
        }

        return ret;
    }
};