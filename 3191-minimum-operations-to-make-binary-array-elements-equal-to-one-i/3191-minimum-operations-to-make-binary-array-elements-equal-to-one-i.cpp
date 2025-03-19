class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                if(i >= n - 2) {
                    return -1;
                }
                ret++;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
            }
        }

        return ret;
    }
};