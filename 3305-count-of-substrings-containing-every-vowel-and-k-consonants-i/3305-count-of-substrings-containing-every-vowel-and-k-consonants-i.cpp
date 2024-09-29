class Solution {
public:
    int countOfSubstrings(string word, int k) {
        return countAtLeastK(word, k) - countAtLeastK(word, k + 1);       
    }

    int countAtLeastK(const string &w, int k) {
        int n = w.length();
        int ret = 0;
        unordered_map<char, int> vowel;

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
        static const unordered_set<char> s{'a', 'e', 'i', 'o', 'u'};
        return s.find(c) != s.end();
    }

    bool ok(unordered_map<char, int> &m) {
        return m['a'] > 0 && m['e'] > 0 && m['i'] > 0 && m['o'] > 0 && m['u'] > 0;
    } 
};