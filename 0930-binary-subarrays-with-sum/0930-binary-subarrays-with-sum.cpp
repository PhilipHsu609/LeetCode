class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ret = 0;
        int sum = 0;
        unordered_map<int, int> prefix;

        prefix[0] = 1;
        for(int n : nums) {
            sum += n;
            ret += prefix[sum - goal];
            ++prefix[sum];
        }

        return ret;
    }
};