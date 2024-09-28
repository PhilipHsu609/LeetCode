class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) {
            return INT_MAX;
        }

        if(dividend == 0) {
            return 0;
        }

        bool neg = false;
        if(dividend < 0) {
            neg = !neg;
        }
        if(divisor < 0) {
            neg = !neg;
        }

        long long x = llabs(dividend);
        long long y = llabs(divisor);

        long long ret = 0;
        while(x >= y) {
            long long tmp = y;
            long long count = 1;

            while((tmp << 1) <= x) {
                tmp <<= 1;
                count <<= 1;
            }

            ret += count;
            x -= tmp;
        }

        if(neg) {
            ret = -ret;
        }

        if(ret > INT_MAX) {
            return INT_MAX;
        }
        if(ret < INT_MIN) {
            return INT_MIN;
        }
        return ret;
    }
};