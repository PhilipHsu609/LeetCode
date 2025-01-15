class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n1 = numBits(num1);
        int n2 = numBits(num2);

        if(n1 == n2) {
            return num1;
        }

        int mask = 1;
        if(n1 > n2) {
            while(n1 > n2) {
                if((num1 & mask) != 0) {
                    num1 ^= mask;
                    n1--;
                }
                mask <<= 1;
            }
            return num1;
        }

        while(n1 < n2) {
            if((num1 & mask) == 0) {
                num1 ^= mask;
                n1++;
            }
            mask <<= 1;
        }
        return num1;
    }

    int numBits(int n) {
        int ret = 0;
        while(n > 0) {
            ret += (n & 1);
            n >>= 1;
        }
        return ret;
    }
};