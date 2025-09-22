class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for(int n : nums) {
            freq[n]++;
            maxFreq = max(maxFreq, freq[n]);
        }

        int ret = 0;
        for(auto [k, v] : freq) {
            if(v == maxFreq) {
                ret += v;
            }
        }
        return ret;
    }
};