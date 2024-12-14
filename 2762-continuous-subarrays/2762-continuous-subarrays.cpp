class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ret = 0;
        int n = nums.size();

        int l = 0, r = 0;
        for(int i = 0, j = 0; i < n; i++) {
            if(i == 0) {
                ret += 1;
                l = nums[i] - 2;
                r = nums[i] + 2;
            } else if(l <= nums[i] && nums[i] <= r) {
                // subarray [j, i]
                l = max(l, nums[i] - 2);
                r = max(r, nums[i] + 2);
                ret += i - j + 1; // every subarray of [j, i] that ended at i is a valid subarray
            } else {
                // start a new subarray [i - 1, i]
                j = i - 1;
                l = nums[i] - 2, r = nums[i] + 2;

                // expand the subarray to the left
                while(nums[i] - 2 <= nums[j] && nums[j] <= nums[i] + 2) {
                    l = max(l, nums[j] - 2);
                    r = max(r, nums[j] + 2);
                    j--;
                }
                j++;

                ret += i - j + 1;
            }
        }

        return ret;
    }
};