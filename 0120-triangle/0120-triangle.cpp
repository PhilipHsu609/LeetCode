class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, INT_MAX);

        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j >= 1; j--) {
                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }

        return *min_element(dp.begin(), dp.end());
    }
};