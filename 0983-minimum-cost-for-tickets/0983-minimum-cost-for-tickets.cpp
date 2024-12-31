class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastday = days.back();
        vector<int> dp(lastday + 1, 0);

        for(int i = 0, day = 1; day <= lastday; day++) {
            if(day < days[i]) {
                dp[day] = dp[day - 1];
            } else {
                i++;
                dp[day] = min({
                    dp[day - 1] + costs[0],
                    dp[max(0, day - 7)] + costs[1],
                    dp[max(0, day - 30)] + costs[2]
                });
            }
        }

        return dp.back();
    }
};