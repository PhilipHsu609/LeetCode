class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return countAtLeastK(word, k) - countAtLeastK(word, k + 1);
    }

    long long countAtLeastK(const string &w, int k) {
        int n = w.length();
        unordered_map<char, int> vowel;

        long long ret = 0;
        for(int start = 0, end = 0; end < n; end++) {
            if(isVowel(w[end])) {
                vowel[w[end]]++;
            } else {
                k--;
            }

            while(ok(vowel) && k <= 0) {
                ret += n - end;

                if(isVowel(w[start])) {
                    vowel[w[start]]--;
                } else {
                    k++;
                }
                start++;
            }
        }

        return ret;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool ok(unordered_map<char, int> &m) {
        return m['a'] > 0 && m['e'] > 0 && m['i'] > 0 && m['o'] > 0 && m['u'] > 0;
    }
};