class Solution {
public:
    int longestAwesome(string s) {
        int n = s.length();
        unordered_map<int, int> m; // bitmap -> index
        m[0] = -1;

        int cnt = 0, ret = 0;
        for(int i = 0; i < n; i++) {
            int d = s[i] - '0';

            cnt ^= 1 << d;
            
            // no odd character
            if(m.find(cnt) == m.end()) {
                m[cnt] = i;
            } else {
                ret = max(ret, i - m[cnt]);
            }

            // has one odd character
            for(int j = 0; j < 10; j++) {
                int x = cnt ^ (1 << j);
                if(m.find(x) != m.end()) {
                    ret = max(ret, i - m[x]);
                }
            }
        }

        return ret;
    }
};