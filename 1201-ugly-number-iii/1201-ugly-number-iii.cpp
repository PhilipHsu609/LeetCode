class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int l = 1, r = INT_MAX;

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(count(mid, a, b, c) < n) {
                l = mid + 1;
            } else {
                r = mid;
            }
        } 

        return l;
    }

    int count(long long m, long long a, long long b, long long c) {
        return m/a + m/b + m/c - m/lcm(a, b) - m/lcm(b, c) - m/lcm(a, c) - m/lcm(lcm(a, b), c);
    }

    long long gcd(long long a, long long b) {
        if(b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return a * b / gcd(a, b);
    }
};