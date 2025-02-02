class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int i = 1;

        while(i < n) {
            if(nums[i - 1] > nums[i]) {
                break;
            }
            i++;
        }

        if(i == n) {
            return true;
        }

        i++;
        while(i < n) {
            if(nums[i - 1] > nums[i]) {
                return false;
            }
            i++;
        }

        return nums.front() >= nums.back();
    }
};