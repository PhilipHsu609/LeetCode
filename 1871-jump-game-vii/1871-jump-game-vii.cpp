class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<int> diffdp(n + maxJump + 2);
        diffdp[minJump] += 1;
        diffdp[maxJump + 1] -= 1; 

        int jump = 0;
        for(int i = 1; i < n; ++i) {
            jump += diffdp[i];

            if(jump == 0 || s[i] == '1') {
                continue;
            }

            diffdp[i + minJump] += 1;
            diffdp[i + maxJump + 1] -= 1;
        }

        return jump > 0 && s.back() == '0';
    }
};