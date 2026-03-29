class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool ans;
        ans = min(s1[0], s1[2]) == min(s2[0], s2[2]);
        ans = ans && max(s1[0], s1[2]) == max(s2[0], s2[2]);
        ans = ans && min(s1[1], s1[3]) == min(s2[1], s2[3]);
        ans = ans && max(s1[1], s1[3]) == max(s2[1], s2[3]);
        return ans;
    }
};