class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int x = 0;
        int mask = (1 << maximumBit) - 1;
        
        for(int num : nums) {
            x ^= num;
        }

        vector<int> ret(n);
        for(int i = 0; i < n; i++) {
            ret[i] = x ^ mask;
            x ^= nums[n - 1 - i];
        }

        return ret;
    }
};