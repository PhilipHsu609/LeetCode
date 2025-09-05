class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int k = 1; k <= 60; k++) {
            long long target = num1 - k * static_cast<long long>(num2);
            if( __builtin_popcountll(target) <= k && k <= target) {
                return k;
            }
        }
        return -1;
    }
};

/*

(p_1, p_2, ..., p_k) p_i \in [0, 60], k > 0

num1 - (\sum_{i=1}^{k} {2^{p_i} + num2}) = 0

\implies num1 = \sum_{i=1}^{k} {2^{p_i} + num2}

\implies num1 - k * num2 = \sum_{i=1}^{k} 2^{p_i} > 0

k can be at least bit_count(num1 - k * num2)
k can be at most (num1 - k * num2), why? 2^0 * (num1 - k * num2)

---

find a k such that (num1 - k * num2) satisfy the boundary:

bit_count(num1 - k * num2) <= k <= num1 - k * num2

*/