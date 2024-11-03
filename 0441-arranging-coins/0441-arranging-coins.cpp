class Solution {
public:
    int arrangeCoins(int n) {
        int r = 0;
        while(n >= 0) {
            r++;
            n -= r;
        }
        return r - 1; 
    }
};