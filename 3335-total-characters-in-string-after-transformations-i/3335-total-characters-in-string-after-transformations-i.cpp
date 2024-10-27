class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int n = s.length();
        int MOD = 1e9 + 7;
        vector<int> freq(26);

        for(char ch : s) {
            freq[ch - 'a']++;
        }

        for(int i = 0; i < t; i++) {
            vector<int> nfreq(26);
            for(int j = 0; j < 25; j++) {
                nfreq[j + 1] = freq[j];
            }

            nfreq[0] = freq[25];
            nfreq[1] = (nfreq[1] + freq[25]) % MOD;

            freq = nfreq;
        }

        int ret = 0;
        for(int v : freq) {
            ret = (ret + v) % MOD;
        }

        return ret;
    }
};