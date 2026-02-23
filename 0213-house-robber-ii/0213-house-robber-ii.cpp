class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max({
            nums[0] + helper(nums, 2, n - 2),
            helper(nums, 1, n - 3) + nums[n - 1],
            helper(nums, 1, n - 2)
        });
    }

    int helper(const vector<int> &nums, int i, int j) {
        int y = 0, n = 0;
        for(int k = i; k <= j; ++k) {
            int tmp = n + nums[k];
            n = max(n, y);
            y = tmp;
        }
        return max(y, n);
    }
};