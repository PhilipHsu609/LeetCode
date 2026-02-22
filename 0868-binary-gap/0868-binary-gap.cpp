class Solution {
public:
    int binaryGap(int n) {
        int ret = 0;
        int last = -1;
        int pos = 0;

        while(n > 0) {
            if((n & 1) == 1) {
                if(last != -1) {
                    ret = max(ret, pos - last);
                }
                last = pos;
            }
            ++pos;
            n >>= 1;
        }

        return ret;
    }
};