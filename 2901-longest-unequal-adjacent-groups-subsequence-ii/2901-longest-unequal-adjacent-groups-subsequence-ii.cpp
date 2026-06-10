class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        int maxLenIdx = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(groups[i] != groups[j] && words[i].length() == words[j].length() && dist(words[i], words[j]) == 1) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if(dp[i] > dp[maxLenIdx]) {
                maxLenIdx = i;
            }
        }

        vector<string> ret;
        while(maxLenIdx != -1) {
            ret.push_back(words[maxLenIdx]);
            maxLenIdx = prev[maxLenIdx];
        }

        ranges::reverse(ret);
        return ret;
    }

    int dist(string_view a, string_view b) {
        int n = a.length();
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            cnt += a[i] != b[i];
        }
        return cnt;
    }
};