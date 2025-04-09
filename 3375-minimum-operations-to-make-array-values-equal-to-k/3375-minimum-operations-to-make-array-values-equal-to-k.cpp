class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int n : nums) {
            if(n < k) {
                return -1;
            }
            if(n == k) {
                continue;
            }
            freq[n]++;
        }

        return static_cast<int>(freq.size());
    }
};