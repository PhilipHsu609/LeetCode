class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> seen;

        int ret = 0;
        for(int start = 0, end = 0; end < n; end++) {
            if(seen.find(s[end]) == seen.end()) {
                seen.insert(s[end]);
            } else {
                while(s[start] != s[end]) {
                    seen.erase(s[start]);
                    start++;
                }
                start++;
            }

            ret = max(ret, end - start + 1);
        }

        return ret;
    }
};