class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int psum = 0;
        array<int, 2> cnt{};
        cnt[0] = 1;

        int ret = 0, MOD = 1e9 + 7;
        for(int n : arr) {
            psum += n;

            if(psum % 2 == 1) {
                ret = (ret + cnt[0]) % MOD;
            } else {
                ret = (ret + cnt[1]) % MOD;
            }

            cnt[psum % 2]++;
        }

        return ret;
    }
};