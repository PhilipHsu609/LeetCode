class Solution {
public:
    long long minEnd(int n, int x) {
        long long ret = x;
        int i = 0;

        n--;
        while(n > 0) {
            while((x & (1 << i)) != 0) {
                i++;
            }
            ret |= (n & 1) << i;
            n >>= 1;
            i++;
        }

        return ret;
    }
};