class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        unordered_map<char, int> mt;

        for(char c : t) {
            mt[c]++;
        }

        int wstart = 0, wlen = n + 1;
        for(int start = 0, end = 0; end < n; end++) {
            mt[s[end]]--;
            if(mt[s[end]] >= 0) {
                m--;
            }

            while(m == 0) {
                if(wlen > end - start + 1) {
                    wstart = start;
                    wlen = end - start + 1;
                }
                mt[s[start]]++;
                if(mt[s[start]] > 0) {
                    m++;
                }
                start++;
            }
        }

        return wlen == n + 1 ? "" : s.substr(wstart, wlen);
    }
};