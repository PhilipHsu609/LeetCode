class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();
        unordered_map<char, int> freq;
        unordered_map<char, int> firstOcc;

        for(int i = 0; i < n; ++i) {
            char ch = s[i];
            if(isVowel(ch)) {
                ++freq[ch];
            }
            if(firstOcc.find(ch) == firstOcc.end()) {
                firstOcc[ch] = i;
            }
        }

        vector<pair<char, int>> vowels(freq.begin(), freq.end());
        sort(vowels.begin(), vowels.end(), [&](const auto &a, const auto &b) {
            if(a.second != b.second) {
                return a.second > b.second;
            }
            return firstOcc[a.first] < firstOcc[b.first];
        });

        int j = 0;
        for(int i = 0; i < n; ++i) {
            if(isVowel(s[i])) {
                s[i] = vowels[j].first;
                if(--vowels[j].second == 0) {
                    ++j;
                }
            }
        }

        return s;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};