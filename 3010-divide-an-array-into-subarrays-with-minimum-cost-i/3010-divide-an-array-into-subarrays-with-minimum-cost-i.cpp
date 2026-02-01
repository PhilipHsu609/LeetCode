class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ret = nums[0];

        int n = nums.size();
        int mini1 = INT_MAX, mini2 = INT_MAX;
        for(int i = 1; i < n; ++i) {
            if(nums[i] < mini1) {
                mini2 = min(mini2, mini1);
                mini1 = nums[i];
            } else if(nums[i] < mini2) {
                mini1 = min(mini1, mini2);
                mini2 = nums[i];
            }
        }
        return ret + mini1 + mini2;
    }
};