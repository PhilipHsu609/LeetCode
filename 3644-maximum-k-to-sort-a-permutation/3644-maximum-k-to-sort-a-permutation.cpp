class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ret = INT_MAX;
        for(int i = 0; i < n; ++i) {
            if(nums[i] != i) {
                ret &= nums[i];
            }
        }
        return ret == INT_MAX ? 0 : ret;
    }
};