class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ret = 1;
        int n = prices.size();
        vector<int> dp(n, 1);

        for(int i = 1; i < n; ++i) {
            if(prices[i - 1] == prices[i] + 1) {
                dp[i] += dp[i - 1];
            }
            ret += dp[i];
        }
        return ret;
    }
};