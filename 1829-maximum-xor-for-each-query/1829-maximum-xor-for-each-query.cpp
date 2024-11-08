class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int x = 0;
        
        for(int num : nums) {
            x ^= num;
        }

        vector<int> ret(n);
        for(int i = n - 1; i >= 0; i--) {
            int k = 0;
            for(int b = 0; b < maximumBit; b++) {
                if((x & (1 << b)) == 0) {
                    k |= 1 << b;
                }
            }
            ret[i] = k;
            x ^= nums[i];
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};