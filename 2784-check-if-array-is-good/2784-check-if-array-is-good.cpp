class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if(nums[0] != 1) {
            return false;
        }

        int n = nums.size() - 1;
        for(int i = 1; i < n; ++i) {
            if(nums[i - 1] != nums[i] - 1) {
                return false;
            }
        }

        return nums.back() == n;
    }
};