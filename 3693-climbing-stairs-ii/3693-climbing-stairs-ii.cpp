class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n == 1) {
            return costs[0] + 1;
        }

        vector<int> dp(n + 1);
        dp[1] = costs[0] + 1;
        dp[2] = min(dp[1] + costs[1] + 1, dp[0] + costs[1] + 4);

        for(int i = 3; i <= n; ++i) {
            dp[i] = min({
                dp[i - 1] + costs[i - 1] + 1,
                dp[i - 2] + costs[i - 1] + 4,
                dp[i - 3] + costs[i - 1] + 9
            });
        }

        return dp.back();
    }
};

/*
dp[i] := min cost to reach step i => dp[n]

dp[i] = min(
    dp[i - 1] + cost[i - 1] + 1,
    dp[i - 2] + cost[i - 1] + 4,
    dp[i - 3] + cost[i - 1] + 9
)

dp[0] = 0
dp[1] = cost[0] + 1
dp[2] = cost[1] + 4, cost[0] + 1 + cost[1]
*/