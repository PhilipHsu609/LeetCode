class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n > 2) {
            int mod = n % 3;

            if(mod == 2) {
                return false;
            }

            n /= 3;
        }
        return n != 2;
    }
};