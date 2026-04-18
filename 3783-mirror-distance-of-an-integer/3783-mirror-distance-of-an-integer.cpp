class Solution {
public:
    int mirrorDistance(int n) {
        return abs(n - rev(n));
    }

    int rev(int x) {
        int ret = 0;
        while(x > 0) {
            ret *= 10;
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }
};