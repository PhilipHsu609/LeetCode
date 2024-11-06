class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        if(is_sorted(begin(nums), end(nums))) {
            return true;
        }

        int n = nums.size();
        int last = 0;
        int maxi = nums[0];

        for(int i = 1; i < n; i++) {
            if(bc(nums[i - 1]) != bc(nums[i])) {
                last = maxi;
                maxi = nums[i];
            }
            if(nums[i] < last) {
                return false;
            }
            maxi = max(maxi, nums[i]);
        }

        return true;
    }

    int bc(int n) {
        int c = 0;
        while(n > 0) {
            c += n & 1;
            n >>= 1;
        }
        return c;
    }
};