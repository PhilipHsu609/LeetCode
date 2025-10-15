class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        nums.push_back(INT_MIN);
        
        int n = nums.size();
        int ret = 1;
        int last_end = -1;
        int last_len = 0;

        for(int start = 0, end = 0; end < n; end++) {
            if(end > 0 && nums[end - 1] >= nums[end]) {
                if(last_end + 1 == start) {
                    ret = max(ret, min(end - start, last_len));
                }
                last_end = end - 1;
                last_len = end - start;
                start = end;
            }
            if((end - start + 1) % 2 == 0) {
                ret = max(ret, (end - start + 1) / 2);
            }
        }

        return ret;
    }
};