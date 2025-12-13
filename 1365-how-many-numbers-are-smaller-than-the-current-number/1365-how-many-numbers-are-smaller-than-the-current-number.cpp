class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> dup(nums);
        sort(dup.begin(), dup.end());
        vector<int> ret;
        for(int n : nums) {
            ret.push_back(distance(dup.begin(), lower_bound(dup.begin(), dup.end(), n)));
        }
        return ret;
    }
};