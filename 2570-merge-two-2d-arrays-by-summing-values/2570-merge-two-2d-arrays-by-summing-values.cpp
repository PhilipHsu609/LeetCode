class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        if(nums2[0][0] < nums1[0][0]) {
            swap(nums1, nums2);
        }
        
        int m = nums1.size(), n = nums2.size();
        int i = 1, j = 0;

        vector<vector<int>> ret;
        ret.push_back(nums1[0]);

        while(i < m || j < n) {
            if(i < m && nums1[i][0] == ret.back()[0]) {
                ret.back()[1] += nums1[i][1];
                i++;
                continue;
            }

            if(j < n && nums2[j][0] == ret.back()[0]) {
                ret.back()[1] += nums2[j][1];
                j++;
                continue;
            }

            if(i < m && j < n) {
                if(nums1[i][0] < nums2[j][0]) {
                    ret.push_back(nums1[i]);
                    i++;
                } else {
                    ret.push_back(nums2[j]);
                    j++;
                }
                continue;
            }

            if(i < m) {
                ret.push_back(nums1[i]);
                i++;
                continue;
            }

            if(j < n) {
                ret.push_back(nums2[j]);
                j++;
                continue;
            }
        }

        return ret;
    }
};