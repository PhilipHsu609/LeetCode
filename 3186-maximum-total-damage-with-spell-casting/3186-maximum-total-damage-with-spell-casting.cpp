class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();

        sort(power.begin(), power.end());

        vector<long long> dp(n);
        int lastValid = 0;
        long long max_dp = 0;
        long long ret = 0;

        dp[0] = ret = power[0];
        for(int i = 1; i < n; ++i) {
            if(power[i - 1] == power[i]) {
                dp[i] = dp[i - 1] + power[i];
            } else {
                while(lastValid < i && power[lastValid] < power[i] - 2) {
                    max_dp = max(max_dp, dp[lastValid]);
                    ++lastValid;
                }
                dp[i] = max_dp + power[i];
            }

            ret = max(ret, dp[i]);
        }

        return ret;
    }
};