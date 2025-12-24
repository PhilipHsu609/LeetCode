class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 1);

        for(int i = n - 2; i >= 0; --i) {
            ret[i] = ret[i + 1] * nums[i + 1];
        }

        int mul = 1;
        for(int i = 0; i < n; ++i) {
            ret[i] *= mul;
            mul *= nums[i];
        }

        return ret;
    }
};