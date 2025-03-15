class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        auto [minit, maxit] = minmax_element(nums.begin(), nums.end());
        int l = *minit, r = *maxit;

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(good(nums, mid, k)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

    bool good(const vector<int> &nums, int threshold, int size) {
        int n = nums.size();
        int take = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] <= threshold) {
                take++;
                i++;
            }
        }

        return take >= size;
    }
};