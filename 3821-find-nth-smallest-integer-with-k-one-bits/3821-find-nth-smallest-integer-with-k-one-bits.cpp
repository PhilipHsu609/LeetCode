class Solution {
public:
    long long nthSmallest(long long n, int k) {
        if(k == 1) {
            return 1LL << (n - 1);
        }
        if(n == 1) {
            return (1LL << k) - 1;
        }

        int zeros = 0;
        long long cnt = 1;
        while(n - cnt > 0) {
            n -= cnt;
            ++zeros;
            cnt = (cnt * (k - 1LL + zeros)) / zeros;
        }

        long long ret = 1LL << (zeros + k - 1);
        long long lower = nthSmallest(n, k - 1);
        return ret | lower;
    }
};

/*
0 0  -> 2!/2!/0! = 1
111

1 0  -> 3!/2!/1! = 3
1011
1101
1110

2 0   -> 4!/2!/2! = 6
10011
10101
10110
11001
11010
11100

3 0    -> 5!/2!/3! = 10
100011
100101
101001
101010

...

m 0    -> (k - 1 + m)!/(k - 1)!/m! = (k - 1 + m) * (k - 1 + m - 1) /(k - 1)!
111000...0

*/