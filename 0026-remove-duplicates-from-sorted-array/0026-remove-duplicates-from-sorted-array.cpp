class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int ins = 1;
        for(int i = 1; i < n; ++i) {
            if(nums[ins - 1] != nums[i]) {
                nums[ins++] = nums[i];
            }
        }
        return ins;
    }
};