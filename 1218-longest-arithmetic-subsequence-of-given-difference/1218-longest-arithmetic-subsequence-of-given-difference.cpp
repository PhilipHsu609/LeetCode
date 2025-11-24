class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> lastSeen;
        int ret = 1;

        for(int n : arr) {
            if(lastSeen.find(n - difference) != lastSeen.end()) {
                lastSeen[n] = max(lastSeen[n], lastSeen[n - difference] + 1);
                ret = max(ret, lastSeen[n]);
            } else {
                lastSeen[n] = 1;
            }
        }

        return ret;
    }
};