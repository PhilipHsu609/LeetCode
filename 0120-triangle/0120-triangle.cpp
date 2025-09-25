class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        int ret = 0;
        for(int i = 0; i < n; i++) {
            int curMin = INT_MAX;
            for(int j = i; j >= 1; j--) {
                dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
                curMin = min(curMin, dp[j]);
            }
            dp[0] += triangle[i][0];
            ret = min(curMin, dp[0]);
        }

        return *min_element(dp.begin(), dp.end());
    }
};