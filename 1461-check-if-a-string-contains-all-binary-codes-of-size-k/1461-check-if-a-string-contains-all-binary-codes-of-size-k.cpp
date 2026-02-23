class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length() < k) {
            return false;
        }
        
        int mask = (1 << k) - 1;
        int val = 0;
        unordered_set<int> codes;

        for(int i = 0; i < k - 1; ++i) {
            val <<= 1;
            if(s[i] == '1') {
                val |= 1;
            }
        }

        for(int i = k - 1; i < s.length(); ++i) {
            val <<= 1;
            if(s[i] == '1') {
                val |= 1;
            }
            val &= mask;
            codes.insert(val);
        }

        return codes.size() == (1 << k);
    }
};