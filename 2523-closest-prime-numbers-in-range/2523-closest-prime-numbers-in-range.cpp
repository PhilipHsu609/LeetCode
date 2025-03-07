class Solution {
public:
    vector<bool> sieve;

    vector<int> closestPrimes(int left, int right) {
        buildSieve(right);

        vector<int> p;
        for(int i = left; i <= right; i++) {
            if(sieve[i]) {
                p.push_back(i);
            }
        }

        if(p.size() < 2) {
            return {-1, -1};
        }

        vector<int> ret{0, 1000000};
        for(int i = 0; i < p.size() - 1; i++) {
            if(p[i + 1] - p[i] < ret[1] - ret[0]) {
                ret[0] = p[i];
                ret[1] = p[i + 1];
            }
        }

        return ret;
    }

    void buildSieve(int n) {
        sieve.resize(n + 1, true);

        sieve[0] = sieve[1] = false;

        for(int i = 2; i * i <= n; i++) {
            if(sieve[i] == true) {
                for(int p = i * i; p <= n; p += i) {
                    sieve[p] = false;
                }
            }
        }
    }
};