class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int ret = 0;

        vector<int> dp(n);
        for(int i = 0; i < n; i++) {
            ret = max(ret, 1 + dfs(i, arr, d, dp));
        }

        return ret;
    }

    int dfs(int idx, const vector<int> &arr, int d, vector<int> &dp) {
        if(dp[idx] != 0) {
            return dp[idx];
        }

        int ret = 0;
        int n = arr.size();
        for(int i = idx + 1; i <= min(idx + d, n - 1) && arr[idx] > arr[i]; i++) {
            ret = max(ret, 1 + dfs(i, arr, d, dp));
        }

        for(int i = idx - 1; i >= max(idx - d, 0) && arr[i] < arr[idx]; i--) {
            ret = max(ret, 1 + dfs(i, arr, d, dp));
        }

        return dp[idx] = ret;
    }
};