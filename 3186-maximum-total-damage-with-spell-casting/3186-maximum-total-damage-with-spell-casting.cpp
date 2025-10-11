class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        int j = 0;
        long long max_dp = 0;
        vector<long long> dp(n);

        sort(power.begin(), power.end());

        dp[0] = power[0];
        for(int i = 1; i < n; i++) {
            if(power[i] == power[i - 1]) {
                dp[i] = power[i] + dp[i - 1];
            } else {
                while(power[j] < power[i] - 2) {
                    max_dp = max(max_dp, dp[j]);
                    j++;
                }
                dp[i] = power[i] + max_dp;
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};