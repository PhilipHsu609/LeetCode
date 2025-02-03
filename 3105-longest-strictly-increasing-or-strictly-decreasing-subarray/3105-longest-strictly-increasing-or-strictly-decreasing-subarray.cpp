class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int inc_start = 0, inc_len = 1;
        int dec_start = n - 1, dec_len = 1;

        for(int i = 1; i < n; i++) {
            int j = n - i - 1;

            if(nums[i - 1] < nums[i]) {
                inc_len = max(inc_len, i - inc_start + 1);
            } else {
                inc_start = i;
            }

            if(nums[j] > nums[j + 1]) {
                dec_len = max(dec_len, dec_start - j + 1);
            } else {
                dec_start = j;
            }
        }

        return max(inc_len, dec_len);
    }
};