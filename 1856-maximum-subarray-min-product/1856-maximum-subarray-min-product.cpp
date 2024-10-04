class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> nl(n, n), pl(n, -1);

        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && nums[s.top()] > nums[i]) {
                nl[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        while(!s.empty()) s.pop();

        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && nums[s.top()] > nums[i]) {
                pl[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        vector<long long> psum(n + 1);
        for(int i = 1; i <= n; i++) {
            psum[i] = psum[i - 1] + nums[i - 1];
        }
        
        long long ret = 0;
        int MOD = 1e9 + 7;
        for(int i = 0; i < n; i++) {
            long long sum = psum[nl[i]] - psum[pl[i] == -1 ? 0 : pl[i] + 1];
            long long minprod = sum * nums[i];
            ret = max(ret, minprod);
        }

        return ret % MOD;
    }
};