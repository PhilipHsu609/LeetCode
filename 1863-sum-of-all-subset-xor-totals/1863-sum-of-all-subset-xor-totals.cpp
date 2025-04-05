class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int mask = (1 << n) - 1;
        int ret = 0;

        while(mask > 0) {
            int x = 0;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    x ^= nums[i];
                }
            }
            ret += x;
            mask--;
        }

        return ret;
    }
};