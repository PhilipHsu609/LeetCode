class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        int cnt = 0;

        for(int n : nums) {
            freq[n]++;
            if(freq[n] == maxFreq) {
                cnt++;
            } else if(freq[n] > maxFreq) {
                maxFreq = freq[n];
                cnt = 1;
            }
        }

        return cnt * maxFreq;
    }
};