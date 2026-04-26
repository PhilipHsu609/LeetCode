class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n), r(n);

        l[0] = nums[0];
        r[n - 1] = nums[n - 1];

        for(int i = 1; i < n; ++i) {
            l[i] = max(l[i - 1], nums[i]);
            r[n - 1 - i] = max(r[n - i], nums[n - 1 - i]);
        }

        vector<int> ret;
        for(int i = 0; i < n; ++i) {
            if(i == 0 || i == n - 1) {
                ret.push_back(nums[i]);
                continue;
            }

            if(nums[i] > l[i - 1] || nums[i] > r[i + 1]) {
                ret.push_back(nums[i]);
            }
        }

        return ret;
    }
};