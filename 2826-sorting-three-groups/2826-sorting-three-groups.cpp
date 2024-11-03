class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int dp[4] = {};

        for(int n : nums) {
            dp[1] += n != 1;
            dp[2] = min(dp[1], dp[2] + (n != 2));
            dp[3] = min(dp[2], dp[3] + (n != 3));
        }

        return dp[3];
    }
};