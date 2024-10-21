class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return helper(nums1, nums2) + helper(nums2, nums1);
    }

    int helper(vector<int> &nums1, vector<int> &nums2) {
        int ret = 0;
        unordered_map<int, int> freq;

        for(int n : nums2) {
            freq[n]++;
        }

        for(int n : nums1) {
            long long target = static_cast<long long>(n) * n;

            for(auto [m, cnt] : freq) {
                if(target % m != 0 || freq.find(target / m) == freq.end()) {
                    continue;
                }

                if(target / m == m) {
                    ret += cnt * (cnt - 1);
                } else {
                    ret += cnt * freq[target / m];
                }
            }
        }

        return ret / 2;
    }
};