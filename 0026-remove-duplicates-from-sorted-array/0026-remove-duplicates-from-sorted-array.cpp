class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int insert = 0;

        if(n == 1) {
            return 1;
        }

        int i = 0;
        while(i < n) {
            nums[insert] = nums[i];
            insert++;
            i++;

            while(i > 0 && i < n && nums[i - 1] == nums[i]) {
                i++;
            }
        }

        while(n > insert) {
            nums.pop_back();
            n--;
        }

        return insert;
    }
};