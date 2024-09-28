class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        if((m + n) % 2 == 1) {
            return kthsmallest(nums1, 0, m, nums2, 0, n, (m + n) / 2 + 1);
        } else {
            return (kthsmallest(nums1, 0, m, nums2, 0, n, (m + n) / 2) + kthsmallest(nums1, 0, m, nums2, 0, n, (m + n) / 2 + 1)) / 2.0;
        }
    }

    int kthsmallest(const vector<int> &nums1, int i, int m, const vector<int> &nums2, int j, int n, int k) {
        if(m > n) {
            return kthsmallest(nums2, j, n, nums1, i, m, k);
        }

        if(m == 0) {
            return nums2[j + k - 1];
        }

        if(k == 1) {
            return min(nums1[i], nums2[j]);
        }

        int k1 = min(m, k / 2);
        int k2 = k - k1;

        if(nums1[i + k1 - 1] < nums2[j + k2 - 1]) {
            return kthsmallest(nums1, i + k1, m - k1, nums2, j, n, k - k1);
        }

        return kthsmallest(nums1, i, m, nums2, j + k2, n - k2, k - k2);
    }
};