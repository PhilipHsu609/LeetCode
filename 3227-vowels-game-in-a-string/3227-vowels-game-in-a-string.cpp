class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for(char c : s) {
            cnt += static_cast<int>(isVowel(c));
        }
        if(cnt == 0) {
            return false;
        }
        if(cnt % 2 == 1) {
            return true;
        }
        return true;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};