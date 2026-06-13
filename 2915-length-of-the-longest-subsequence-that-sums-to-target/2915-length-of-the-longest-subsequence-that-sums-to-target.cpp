class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);

        dp[0] = 0;
        for(int n : nums) {
            for(int x = target; x >= n; --x) {
                if(dp[x - n] != -1) {
                    dp[x] = max(dp[x], dp[x - n] + 1);
                }
            }
        }

        return dp.back();
    }
};