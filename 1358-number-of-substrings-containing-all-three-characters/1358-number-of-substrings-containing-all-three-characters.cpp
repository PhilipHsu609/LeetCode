class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        unordered_map<char, int> cnt;

        int ret = 0;
        for(int start = 0, end = 0; end < n; end++) {
            cnt[s[end]]++;

            while(good(cnt)) {
                ret += n - end;
                cnt[s[start]]--;
                start++;
            }
        }

        return ret;
    }

    bool good(unordered_map<char, int> &m) {
        return m['a'] > 0 && m['b'] > 0 && m['c'] > 0;
    }
};