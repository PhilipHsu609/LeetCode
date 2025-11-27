class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ret = numeric_limits<long long>::min();
        vector<long long> p(n + 1);

        for(int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + nums[i - 1];

            long long j = 1;
            while(i >= j * k) {
                ret = max(ret, p[i] - p[i - j * k]);
                j++;
            }
        }

        return ret;
    }
};

/*
prefix[i] - prefix[(i - nk) % k]
*/