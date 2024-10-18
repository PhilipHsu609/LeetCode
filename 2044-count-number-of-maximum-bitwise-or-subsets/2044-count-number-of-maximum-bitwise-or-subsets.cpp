class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for(int num : nums) {
            target = target | num;
        }

        return helper(0, nums, 0, target);
    }

    int helper(int idx, const vector<int> &nums, int bitOR, int target) {
        int n = nums.size();

        if(idx == n) {
            return bitOR == target ? 1 : 0;
        }

        int ret = 0;
        ret += helper(idx + 1, nums, bitOR, target);
        ret += helper(idx + 1, nums, bitOR | nums[idx], target);
        return ret;
    }
};