class Solution {
public:
    int numOfWays(int n) {
        int MOD = 1e9 + 7;
        long p1 = 6; // ABA -> 3 p1 2 p2
        long p2 = 6; // ABC -> 2 p1 2 p2

        if(n == 1) {
            return p1 + p2;
        }

        for(int i = 1; i < n; ++i) {
            int tmp = p1;
            p1 = ((p1 * 3) + (p2 * 2)) % MOD;
            p2 = ((tmp * 2) + (p2 * 2)) % MOD;
        }

        return (p1 + p2) % MOD;
    }
};