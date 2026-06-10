class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int logn = __builtin_clz(n);

        vector<vector<int>> stMax(n, vector<int>(logn));
        vector<vector<int>> stMin(n, vector<int>(logn));

        for(int i = 0; i < n; ++i) {
            stMax[i][0] = stMin[i][0] = nums[i];
        }

        for(int j = 1; j < logn; ++j) {
            for(int i = 0; i + (1 << j) <= n; ++i) {
                stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
                stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            }
        }

        auto queryMax = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return max(stMax[l][j], stMax[r - (1 << j) + 1][j]);
        };
        auto queryMin = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
        };

        priority_queue<array<int, 3>> pq;
        for(int l = 0; l < n; ++l) {
            pq.push({queryMax(l, n - 1) - queryMin(l, n - 1), l, n - 1});
        }

        long long ret = 0;
        while(k--) {
            auto [val, l, r] = pq.top();
            pq.pop();

            ret += val;
            if(r > l) {
                pq.push({queryMax(l, r - 1) - queryMin(l, r - 1), l, r - 1});
            }
        }

        return ret;
    }
};