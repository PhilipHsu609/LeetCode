class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ret(2);

        ret[0] = n - 1;
        ret[1] = 1;
        while(!isNoZero(ret[0]) || !isNoZero(ret[1])) {
            ret[0]--;
            ret[1]++;
        }

        return ret;
    }

    bool isNoZero(int n) {
        while(n > 0) {
            if(n % 10 == 0) {
                return false;
            }
            n /= 10;
        }
        return true;
    }
};