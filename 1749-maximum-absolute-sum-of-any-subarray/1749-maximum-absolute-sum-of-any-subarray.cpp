class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum[2] = {};
        int ret[2] = {};

        for(int n : nums) {
            sum[0] = max(n, sum[0] + n);
            ret[0] = max(ret[0], sum[0]);
            sum[1] = min(n, sum[1] + n);
            ret[1] = min(ret[1], sum[1]);
        }

        return max(ret[0], -ret[1]);
    }
};