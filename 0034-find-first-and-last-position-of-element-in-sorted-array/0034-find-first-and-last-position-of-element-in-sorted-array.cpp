class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2);

        auto l = lower_bound(nums.begin(), nums.end(), target);
        auto r = upper_bound(nums.begin(), nums.end(), target);

        ret[0] = (l != nums.end() && *l == target) ? distance(nums.begin(), l) : -1;
        ret[1] = (r != nums.end() && r != nums.begin() && *prev(r) == target) ? distance(nums.begin(), prev(r)) : -1;

        return ret;
    }
};