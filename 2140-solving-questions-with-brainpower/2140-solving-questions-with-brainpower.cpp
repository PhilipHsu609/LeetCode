class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long ret = 0;
        vector<long long> dp(n);

        dp[n - 1] = questions.back()[0];
        for(int i = n - 1; i >= 0; --i) {
            int p = questions[i][0];
            int b = questions[i][1];

            // skip
            if(i < n - 1) {
                dp[i] = dp[i + 1];
            }
            // solve
            if(i + b + 1 < n) {
                dp[i] = max(dp[i], dp[i + b + 1] + p);
            } else {
                dp[i] = max(dp[i], static_cast<long long>(p));
            }

            ret = max(ret, dp[i]);
        }

        return ret;
    }
};