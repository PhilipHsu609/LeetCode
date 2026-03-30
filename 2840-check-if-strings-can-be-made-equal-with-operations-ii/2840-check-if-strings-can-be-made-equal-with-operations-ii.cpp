class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> v1(26, 0), v2(26, 0);
        for(int i = 0; i < s1.length(); i++) {
            if(i & 1) {
                v1[s1[i] - 'a']++;
                v1[s2[i] - 'a']--;
            } else {
                v2[s1[i] - 'a']++;
                v2[s2[i] - 'a']--;
            }
        }
        
        for(int i = 0; i < 26; i++) {
            if(v1[i] != 0 || v2[i] != 0)
                return false;
        }
        return true;
    }
};