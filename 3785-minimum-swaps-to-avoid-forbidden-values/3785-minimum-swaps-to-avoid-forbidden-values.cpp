class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();
        unordered_map<int, int> freq;
        unordered_map<int, int> badPairCnt;

        int badPairSum = 0;
        int maxBadPair = 0;

        for(int i = 0; i < n; ++i) {
            ++freq[nums[i]];
            ++freq[forbidden[i]];

            if(nums[i] == forbidden[i]) {
                ++badPairCnt[nums[i]];

                ++badPairSum;
                maxBadPair = max(maxBadPair, badPairCnt[nums[i]]);
            }
        }

        for(auto [k, v] : freq) {
            if(v >= n + 1) {
                return -1;
            }
        }

        return max((badPairSum + 1) / 2, maxBadPair);
    }
};