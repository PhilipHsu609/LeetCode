class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> pr(n, -1);

        for(int i = 0; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pr[i] = j;
                }
            }
        }

        vector<int> ret;
        int len = 0;
        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(len < dp[i]) {
                len = dp[i];
                idx = i;
            }
        }

        while(idx != -1) {
            ret.push_back(nums[idx]);
            idx = pr[idx];
        }

        return ret;
    }
};