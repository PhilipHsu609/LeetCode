class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26);

        int vowelFreq = 0;
        int consonantFreq = 0;

        for(char c : s) {
            freq[c - 'a']++;

            if(isVowel(c)) {
                vowelFreq = max(vowelFreq, freq[c - 'a']);
            } else {
                consonantFreq = max(consonantFreq, freq[c - 'a']);
            }
        }

        return vowelFreq + consonantFreq;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};