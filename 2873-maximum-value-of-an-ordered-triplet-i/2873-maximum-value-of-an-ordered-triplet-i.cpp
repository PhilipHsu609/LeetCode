class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxi = 0, maxij = 0;
        long long ret = 0;
        vector<int> s;

        for(int n : nums) {
            ret = max(ret, static_cast<long long>(maxij) * n);
            maxij = max(maxij, maxi - n);
            maxi = max(maxi, n);
        }

        return ret;
    }
};
/*

max_{i, j, k; i < j < k} (nums[i] - nums[j]) * nums[k]

max_{i, j; i < j} (nums[i] - nums[j])

*/