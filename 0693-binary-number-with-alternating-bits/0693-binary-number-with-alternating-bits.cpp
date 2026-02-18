class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = static_cast<int>(n % 2 == 0);
        while(n != 0) {
            if(n % 2 == last) {
                return false;
            }
            last = n % 2;
            n >>= 1;
        }
        return true;
    }
};