class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;
        int MOD = 1e9 + 7;

        long long s1 = 0, s2 = 0;
        long long ret = 0;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                s1 += nums1[i];
                i++;
            } else if(nums1[i] > nums2[j]) {
                s2 += nums2[j];
                j++;
            } else {
                ret += max(s1, s2) + nums1[i];
                s1 = s2 = 0;
                i++, j++;
            }
        }

        while(i < m) {
            s1 += nums1[i];
            i++;
        }

        while(j < n) {
            s2 += nums2[j];
            j++;
        }

        ret += max(s1, s2);

        return static_cast<int>(ret % MOD);
    }
};