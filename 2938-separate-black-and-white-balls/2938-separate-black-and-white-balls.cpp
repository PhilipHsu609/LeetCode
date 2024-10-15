class Solution {
public:
    long long minimumSteps(string s) {
        int pos = 0;
        long long ans = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') {
                ans += i - pos;
                pos++;
            }
        }
        return ans;
    }
};