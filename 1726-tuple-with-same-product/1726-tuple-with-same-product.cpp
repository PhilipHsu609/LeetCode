class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                m[nums[i] * nums[j]]++;
            }
        }

        int ret = 0;
        for(auto [k, v] : m) {
            ret += v * (v - 1) * 4;
        }

        return ret;
    }
};