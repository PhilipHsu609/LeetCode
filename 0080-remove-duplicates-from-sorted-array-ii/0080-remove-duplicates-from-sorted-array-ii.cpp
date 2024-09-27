class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        for(int n : nums) {
            if(pos < 2 || nums[pos - 2] < n) {
                nums[pos] = n;
                pos++;
            }
        }    
        return pos;
    }
};