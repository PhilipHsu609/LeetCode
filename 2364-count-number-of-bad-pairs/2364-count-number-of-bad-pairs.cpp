class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;

        long long good = 0;
        for(int i = 0; i < n; i++) {
            good += m[nums[i] - i]++;
        }

        return (static_cast<long long>(n) * (n - 1)) / 2 - good;
    }
};