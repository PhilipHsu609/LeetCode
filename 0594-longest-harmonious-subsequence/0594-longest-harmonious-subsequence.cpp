class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int n : nums) {
            freq[n]++;
        }

        int ret = 0;
        for(auto [k, v] : freq) {
            if(freq.find(k + 1) != freq.end()) {
                ret = max(ret, v + freq[k + 1]);
            }
        }

        return ret;
    }
};