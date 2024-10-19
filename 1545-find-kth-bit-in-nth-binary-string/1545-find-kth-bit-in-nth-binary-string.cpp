class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) {
            return '0';
        }

        int half = 1 << (n - 1);
        if(k == half) {
            return '1';
        }

        if(k > half) {
            return findKthBit(n - 1, (1 << n) - k) == '0' ? '1' : '0';
        }

        return findKthBit(n - 1, k);
    }
};
