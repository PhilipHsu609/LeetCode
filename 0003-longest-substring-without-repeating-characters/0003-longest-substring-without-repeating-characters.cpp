class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> seen;

        int ret = 0;
        for(int start = 0, end = 0; end < n; end++) {
            if(seen.find(s[end]) != seen.end() && seen[s[end]] >= start) {
                start = seen[s[end]] + 1;
            }
            ret = max(ret, end - start + 1);
            seen[s[end]] = end;
        }

        return ret;
    }
};