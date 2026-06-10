class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long ret = 0;
        int append = INT_MAX;

        for(int i = 0; i < n; ++i) {
            if(min(nums1[i], nums2[i]) <= nums2.back() && nums2.back() <= max(nums1[i], nums2[i])) {
                append = 0;
            } else {
                append = min({append, abs(nums1[i] - nums2.back()), abs(nums2[i] - nums2.back())});
            }
            ret += abs(nums1[i] - nums2[i]);
        }

        return ret + append + 1;
    }
};