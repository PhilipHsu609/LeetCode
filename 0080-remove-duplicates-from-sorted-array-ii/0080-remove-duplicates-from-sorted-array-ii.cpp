class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 1, j = 2;

        if(n == 1) {
            return 1;
        }

        while(j < n) {
            if(nums[j] == nums[i] && nums[j] == nums[i - 1]) {
                j++;
            } else {
                i++;
                nums[i] = nums[j];
                j++;
            }
        }

        return i + 1;
    }
};
