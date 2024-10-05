class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();

        vector<int> freq(26, 0);
        for(char c : s1) {
            freq[c - 'a']++;
        }

        vector<int> cfreq(26, 0);
        for(int start = 0, end = 0; end < n; end++) {
            cfreq[s2[end] - 'a']++;

            if(end - start + 1 == m) {
                if(cfreq == freq) {
                    return true;
                }
                cfreq[s2[start] - 'a']--;
                start++;
            }
        }

        return false;
    }
};