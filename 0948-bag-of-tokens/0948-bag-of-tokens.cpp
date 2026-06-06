class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        ranges::sort(tokens);

        int l = 0, r = tokens.size() - 1;
        int score = 0;
        int ret = 0;

        while(l <= r) {
            if(power >= tokens[l]) {
                ++score;
                power -= tokens[l];
                ++l;
            } else if(score > 0) {
                --score;
                power += tokens[r];
                --r;
            } else {
                break;
            }
            ret = max(ret, score);
        }
        return ret;
    }
};