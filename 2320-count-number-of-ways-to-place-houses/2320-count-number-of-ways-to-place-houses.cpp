class Solution {
public:
    int countHousePlacements(int n) {
        int MOD = 1e9 + 7;
        int yes = 1, no = 1;
        for(int i = 1; i < n; ++i) {
            int tmp = yes;
            yes = no;
            no = (no + tmp) % MOD;
        }

        int sum = (yes + no) % MOD;
        return (1LL * sum * sum) % MOD;
    }
};