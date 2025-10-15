class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        int len = 1;
        int last_len = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i - 1] >= nums[i]) {
                last_len = len;
                len = 1;
            } else {
                len++;
            }
            ret = max({ret, len / 2, min(len, last_len)});
        }

        return ret;
    }
};