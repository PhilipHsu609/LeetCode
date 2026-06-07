class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        int maxi = INT_MIN, mini = INT_MAX;
        long long ret = LLONG_MIN;

        for(int i = m - 1; i < n; ++i) {
            maxi = max(maxi, nums[i - m + 1]);
            mini = min(mini, nums[i - m + 1]);
            ret = max({
                ret, 1LL * maxi * nums[i], 1LL * mini * nums[i]
            });
        }

        return ret;
    }
};