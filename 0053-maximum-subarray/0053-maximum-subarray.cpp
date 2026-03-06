class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = INT_MIN;
        int sum = 0;

        for(int n : nums) {
            sum = max(n, sum + n);
            ret = max(ret, sum);
        }

        return ret;
    }
};