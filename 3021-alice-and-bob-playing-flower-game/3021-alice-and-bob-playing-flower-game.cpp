class Solution {
public:
    long long flowerGame(int n, int m) {
        int even_n = n / 2;
        int odd_n = (n + 1) / 2;
        int even_m = m / 2;
        int odd_m = (m + 1) / 2;
        return static_cast<long long>(even_n) * odd_m + static_cast<long long>(odd_n) * even_m;
    }
};