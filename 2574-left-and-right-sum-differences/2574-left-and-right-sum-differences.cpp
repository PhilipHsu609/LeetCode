class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ret(n);

        for(int i = 0; i < n; ++i) {
            rightSum -= nums[i];
            ret[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }

        return ret;
    }
};