class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        int f = 0;

        // F(0)
        for(int i = 0; i < n; ++i) {
            total += nums[i];
            f += i * nums[i];
        }

        int ret = f;

        // F(1) ... F(n - 1)
        for(int i = 1; i < n; ++i) {
            f += total;
            f -= nums[n - i] * n;
            ret = max(ret, f);
        }

        return ret;
    }
};

/*

0 1 2 3 4
0 1 2 3 4

0 1 2 3 4
1 2 3 4 0

0 1 2 3 4
2 3 4 0 1
*/