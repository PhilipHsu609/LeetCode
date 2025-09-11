class Solution {
public:
    string sortVowels(string s) {
        vector<int> freq(128);

        for(char c : s) {
            freq[c]++;
        }

        int v = 0;
        for(char &c : s) {
            if(!isVowel(c)) {
                continue;
            }

            while(!isVowel(static_cast<char>(v)) || freq[v] == 0) {
                v++;
            }

            c = static_cast<char>(v);
            freq[v]--;
        }

        return s;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};