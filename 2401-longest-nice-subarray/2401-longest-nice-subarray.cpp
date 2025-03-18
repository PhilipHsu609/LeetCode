class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int used = 0;
        int ret = 0;
        int n = nums.size();

        for(int start = 0, end = 0; end < n; end++) {
            while((used & nums[end]) != 0) {
                used ^= nums[start++];
            }
            used |= nums[end];
            ret = max(ret, end - start + 1);
        }
        
        return ret;
    }
};