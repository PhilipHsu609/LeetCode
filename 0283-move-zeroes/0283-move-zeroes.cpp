class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int ins = 0;

        for(int i = 0; i < n; ++i) {
            if(nums[i] != 0) {
                nums[ins++] = nums[i];
            }
        }
        while(ins < n) {
            nums[ins++] = 0;
        }
    }
};