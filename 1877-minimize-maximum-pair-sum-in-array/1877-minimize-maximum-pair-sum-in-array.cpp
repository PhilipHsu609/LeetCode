class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ret = 0;
        int l = 0, r = n - 1;
        while(l < r) {
            ret = max(ret, nums[l] + nums[r]);
            ++l, --r;
        }
        return ret;
    }
};