class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] > nums[i]) {
                if(count > 0)
                    return false;
                if(i > 1 && i + 1 < n && nums[i - 1] > nums[i + 1] && nums[i - 2] > nums[i])
                    return false;
                count++;
            }
        }
        return true;
    }
};