class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n + 1, vector<int>(target + 1,  -1));
        return helper(n, k, target, memo);
    }

    int helper(int n, int k, int target, vector<vector<int>> &memo) {
        if(n == 0 || target < 0) {
            return 0;
        }
        if(n == 1 && target >= 1 && target <= k) {
            return 1;
        }
        if(memo[n][target] != -1) {
            return memo[n][target];
        }

        int mod = 1e9 + 7;
        int ret = 0;
        for(int i = 1; i <= k; ++i) {
            ret = (ret + helper(n - 1, k, target - i, memo)) % mod;
        }

        return memo[n][target] = ret;
    }
};

/*
f(n, k, t) = f(n - 1, k, t - 1) + f(n - 1, k, t - 2) + ... f(n - 1, k, t - k)
*/