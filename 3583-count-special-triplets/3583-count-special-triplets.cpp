class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        int MOD = 1e9 + 7;

        unordered_map<int, int> l, r;
        for(int n : nums) {
            ++r[n];
        }

        int ret = 0;
        for(int n : nums) {
            --r[n];
            ret = (ret + 1LL * l[n * 2] * r[n * 2]) % MOD;
            ++l[n];
        }

        return ret;
    }
};