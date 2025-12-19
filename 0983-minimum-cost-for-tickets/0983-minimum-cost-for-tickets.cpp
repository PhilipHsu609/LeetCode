class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.back();
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;
        for(int i = 1, d = 0; i <= n; ++i) {
            if(i != days[d]) {
                dp[i] = dp[i - 1];
                continue;
            }
            dp[i] = min(dp[i], dp[i - 1] + costs[0]);
            dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]);
            dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
            ++d;
        }

        return dp[n];
    }
};
