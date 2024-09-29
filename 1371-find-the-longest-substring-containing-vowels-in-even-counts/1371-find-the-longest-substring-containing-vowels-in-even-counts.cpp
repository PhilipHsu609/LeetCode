class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        int cnt = 0, ret = 0;
        unordered_map<int, int> m;
        m[0] = -1;

        for(int i = 0; i < n; i++) {
            char c = s[i];
            if(c == 'a') cnt ^= 1 << 0;
            else if(c == 'e') cnt ^= 1 << 1;
            else if(c == 'i') cnt ^= 1 << 2;
            else if(c == 'o') cnt ^= 1 << 3;
            else if(c == 'u') cnt ^= 1 << 4;

            if(m.find(cnt) == m.end()) {
                m[cnt] = i;
            }

            ret = max(ret, i - m[cnt]);
        }

        return ret;
    }
};