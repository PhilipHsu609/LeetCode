class Solution {
public:
    int rotatedDigits(int n) {
        // 347

        int ret = 0;
        for(int x = 1; x <= n; ++x) {
            if(good(x)) {
                ++ret;
            }
        }

        return ret;
    }

    bool good(int x) {
        int total = 0;
        int cnt = 0;
        while(x > 0) {
            int r = x % 10;

            if(r == 3 || r == 4 || r == 7) {
                return false;
            }

            if(r == 0 || r == 1 || r == 8) {
                ++cnt;
            }
            ++total;

            x /= 10;
        }

        return total != cnt;
    }
};