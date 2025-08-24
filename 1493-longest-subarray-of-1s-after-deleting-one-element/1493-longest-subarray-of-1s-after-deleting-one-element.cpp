class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        int zeros = 0;

        for(int start = 0, end = 0; end < n; end++) {
            if(nums[end] == 0) {
                zeros++;
            }

            while(zeros > 1) {
                zeros -= static_cast<int>(nums[start] == 0);
                start++;
            }

            ret = max(ret, end - start);
        }

        return ret;
    }
};