class Solution {
public:
    int concatenatedBinary(int n) {
        int MOD = 1e9 + 7;
        int ret = 0;
        int mul = 2;
        for(int x = 1; x <= n; ++x) {
            ret = ((1LL * ret * mul) % MOD + x) % MOD;
            if(x == mul - 1) {
                mul = (mul * 2) % MOD;
            }
        }
        return ret;
    }
};