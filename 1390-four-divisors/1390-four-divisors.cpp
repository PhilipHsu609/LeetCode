class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ret = 0;
        for(int n : nums) {
            int last = 0;
            for(int p = 2; p * p < n; ++p) {
                if(n % p == 0) {
                    if(last == 0) {
                        last = p;
                    } else {
                        last = 0;
                        break;
                    }
                }
            }
            if(last > 0 && last == n / last) {
                ret += 1 + last + n / last + n;
            }
        }
        return ret;
    }
};