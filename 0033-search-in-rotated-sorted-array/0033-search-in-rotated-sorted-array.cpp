class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2; // [l, mid] (mid, r]

            if(nums[mid] == target)
                return mid;

            if(nums[l] <= nums[mid]) {
                // left part is sorted
                if(nums[l] <= target && target <= nums[mid])
                    r = mid;
                else
                    l = mid + 1;
            } else {
                // right part is sorted
                if(nums[mid] <= target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid;
            }
        }

        return -1;
    }
};