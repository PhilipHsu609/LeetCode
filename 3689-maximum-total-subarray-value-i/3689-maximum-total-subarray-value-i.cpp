class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = INT_MIN, mini = INT_MAX;
        for(int n : nums) {
            maxi = max(maxi, n);
            mini = min(mini, n);
        }
        return 1LL * k * (maxi - mini);
    }
};