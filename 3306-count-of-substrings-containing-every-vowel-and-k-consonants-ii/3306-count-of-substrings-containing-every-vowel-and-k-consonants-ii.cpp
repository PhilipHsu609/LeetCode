class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return helper(word, k) - helper(word, k + 1);
    }

    long long helper(const string &word, int k) {
        int n = word.length();
        unordered_map<char, int> vowel;
        int cons = 0;

        long long ret = 0;
        for(int start = 0, end = 0; end < n; end++) {
            if(isVowel(word[end])) {
                vowel[word[end]]++;
            } else {
                cons++;
            }

            while(isValid(vowel) && cons >= k) {
                ret += n - end;
                if(isVowel(word[start])) {
                    vowel[word[start]]--;
                } else {
                    cons--;
                }
                start++;
            }
        }

        return ret;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool isValid(unordered_map<char, int> &m) {
        return m['a'] > 0 && m['e'] > 0 && m['i'] > 0 && m['o'] > 0 && m['u'] > 0;
    }
};