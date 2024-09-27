class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int MOD = 1e9 + 7;

        sort(nums.begin(), nums.end());

        vector<int> pow(n, 1);
        for(int i = 1; i < n; i++) {
            pow[i] = pow[i - 1] * 2 % MOD;
        }

        int l = 0, r = n - 1, ret = 0;
        while(l <= r) {
            if(nums[l] + nums[r] <= target) {
                ret = (ret + pow[r - l]) % MOD;
                l++;
            } else {
                r--;
            }
        }

        return ret;
    }
};