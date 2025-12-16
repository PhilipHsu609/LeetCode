class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            return n;
        }
        int ins = 2;
        for(int i = 2; i < n; ++i) {
            if(nums[ins - 2] != nums[i] || nums[ins - 1] != nums[i]) {
                nums[ins++] = nums[i];
            }
        }
        return ins;
    }
};
