class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1;
        for(int i = 0; i < n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};

/*
 n <- n - 1 or n - 2
 n - 1 <- n - 2 or n - 3
 n - 2 <- n - 3 or n - 4
 ...

 n == 1 or 2 -> 1 step
*/