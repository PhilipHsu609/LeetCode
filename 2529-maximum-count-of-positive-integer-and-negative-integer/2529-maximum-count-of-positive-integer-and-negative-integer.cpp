class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto lo = lower_bound(nums.begin(), nums.end(), 0);
        auto hi = upper_bound(nums.begin(), nums.end(), 0);
        return max(distance(nums.begin(), lo), distance(hi, nums.end()));
    }
};