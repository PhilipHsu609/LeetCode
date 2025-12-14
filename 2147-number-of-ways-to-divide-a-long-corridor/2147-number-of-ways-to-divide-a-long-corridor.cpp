class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        int s_cnt = 0;
        int s_last = -1;
        int mod = 1e9 + 7;
        int ret = 1;

        for(int i = 0; i < n; ++i) {
            if(corridor[i] == 'S') {
                ++s_cnt;

                if(s_cnt > 1 && s_cnt % 2 == 1) {
                    ret = (ret * 1LL * (i - s_last)) % mod;
                }

                s_last = i;
            }
        }

        return (s_cnt >= 2 && s_cnt % 2 == 0) ? ret : 0;
    }
};