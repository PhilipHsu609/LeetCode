class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int w = bit_width(1u * ranges::max(nums));
        int b = 1 << w;

        vector<bool> hash2(b);
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                hash2[nums[i] ^ nums[j]] = true;
            }
        }

        vector<int> hash3(b);
        for(int i = 0; i < b; ++i) {
            if(hash2[i]) {
                for(int x : nums) {
                    hash3[i ^ x] = 1;
                }
            }
        }

        return reduce(hash3.begin(), hash3.end());
    }
};
