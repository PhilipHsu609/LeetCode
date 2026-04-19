class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ret = 0;

        for(int i = 0; i < min(nums1.size(), nums2.size()); ++i) {
            auto it = upper_bound(nums2.begin() + i, nums2.end(), nums1[i], greater<int>());
            int j = distance(nums2.begin(), prev(it));
            ret = max(ret, j - i);
        }

        return ret;
    }
};