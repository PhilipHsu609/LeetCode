class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int MOD = 1e9 +7;
        vector<vector<int>> dp(n, vector<int>(forget + 1));

        dp[0][0] = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < forget; j++) {
                dp[i][j] = dp[i - 1][j - 1];
                if(j >= delay) {
                    dp[i][0] = (dp[i][0] + dp[i - 1][j - 1]) % MOD;
                }
            }
        }

        int ret = 0;
        for(int j = 0; j < forget; j++) {
            ret = (ret + dp[n - 1][j]) % MOD;
        }

        return ret;
    }
};

/*

dp[i][j] := the number of people aware of a secret for jth day at day i

dp[i][j] := dp[i - 1][j - 1] * 2
*/