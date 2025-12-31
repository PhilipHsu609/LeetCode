class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back() == '1') {
            return false;
        }

        int n = s.length();
        vector<int> diffdp(n + 1);
        diffdp[minJump] += 1;
        diffdp[maxJump + 1] -= 1; 

        int jump = 0;
        for(int i = 1; i < n; ++i) {
            jump += diffdp[i];

            if(jump == 0 || s[i] == '1') {
                continue;
            }

            if(i + minJump < n + 1)
            diffdp[i + minJump] += 1;

            if(i + maxJump + 1 < n + 1)
            diffdp[i + maxJump + 1] -= 1;
        }

        return jump > 0;
    }
};