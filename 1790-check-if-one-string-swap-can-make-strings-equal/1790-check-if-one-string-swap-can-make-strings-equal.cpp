class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        int diff = 0;
        array<int, 2> pos;

        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                if(diff > 1) {
                    return false;
                }
                pos[diff] = i;
                diff++;
            }
        }

        return diff == 0 || (s1[pos[0]] == s2[pos[1]] && s1[pos[1]] == s2[pos[0]]);
    }
};