class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int, vector<int>> adj;

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = 0;
        function<int(int, int)> dfs = [&](int x, int p) -> int {
            int val = values[x];
            for(auto u : adj[x]) {
                if(u != p) {
                    val += dfs(u, x);
                }
            }
            if(val % k == 0) {
                ans++;
                val = 0;
            }

            return val;
        };

        dfs(0, -1);
        return ans;
    }
};