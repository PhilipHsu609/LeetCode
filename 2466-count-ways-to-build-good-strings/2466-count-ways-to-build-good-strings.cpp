class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        int MOD = 1e9 + 7;
        int ret = 0;

        dp[0] = 1;
        for(int i = 1; i <= high; ++i) {
            // use zero
            if(i >= zero) {
                dp[i] = (dp[i] + dp[i - zero]) % MOD;
            }
            // use one
            if(i >= one) {
                dp[i] = (dp[i] + dp[i - one]) % MOD;
            }

            if(i >= low) {
                ret = (ret + dp[i]) % MOD;
            }
        }

        return ret;
    }
};