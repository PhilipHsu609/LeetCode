class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> m;

        for(const auto &n : nums1) {
            m[n[0]] += n[1];
        }

        for(const auto &n : nums2) {
            m[n[0]] += n[1];
        }

        vector<vector<int>> ret;
        for(const auto [k, v] : m) {
            ret.push_back({k, v});
        }

        return ret;
    }
};