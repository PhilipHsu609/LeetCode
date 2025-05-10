class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zero1 = 0, zero2 = 0;

        for(int n : nums1) {
            sum1 += n;
            zero1 += static_cast<int>(n == 0);
        }

        for(int n : nums2) {
            sum2 += n;
            zero2 += static_cast<int>(n == 0);
        }

        if(zero1 == 0 && zero2 == 0) {
            return sum1 == sum2 ? sum1 : -1;
        }

        if(zero1 == 0) {
            return (sum1 - sum2) >= zero2 ? sum1 : -1;
        }

        if(zero2 == 0) {
            return (sum2 - sum1) >= zero1 ? sum2 : -1;
        }

        return max(sum1 + zero1, sum2 + zero2);
    }
};