class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long ret = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i - 1] > nums[i]) {
                ret += nums[i - 1] - nums[i];
            }
        }
        return ret;
    }
};