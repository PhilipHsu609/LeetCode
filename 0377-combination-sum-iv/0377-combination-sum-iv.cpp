class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int x = 1; x <= target; x++) {
            for(int n : nums) {
                if(x >= n) {
                    dp[x] = (long long)dp[x] + dp[x - n];
                }
            }
        }
        return dp.back();
    }
};