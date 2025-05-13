class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD = 1e9 + 7;
        vector<int> freq(26);

        for(char c : s) {
            freq[c - 'a']++;
        }

        for(int i = 0; i < t; i++) {
            vector<int> nfreq(26);
            
            nfreq[0] = nfreq[1] = freq[25];

            for(int i = 1; i < 26; i++) {
                nfreq[i] = (nfreq[i] + freq[i - 1]) % MOD;
            }

            freq = nfreq;
        }

        int ret = 0;
        for(int f : freq) {
            ret = (ret + f) % MOD;
        }

        return ret;
    }
};