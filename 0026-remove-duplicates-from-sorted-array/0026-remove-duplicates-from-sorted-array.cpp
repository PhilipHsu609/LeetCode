class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int pos = 1;

        for(int i = 1; i < n; i++) {
            if(nums[pos - 1] < nums[i]) {
                nums[pos] = nums[i];
                pos++;
            }
        }
        
        return pos;
    }
};