class Solution {
public:
    int pow(int b, int p, int mod) {
        int ret = 1;
        while(p > 0) {
            if(p % 2 == 1) {
                ret = 1LL * ret * b % mod;
            }
            b = 1LL * b * b % mod;
            p /= 2;
        }
        return ret;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);

        for(const auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        auto dfs = [&](this auto &&self, int p, int u, const vector<vector<int>> &adj) -> int {
            int d = 0;
            for(int v : adj[u]) {
                if(v == p) {
                    continue;
                }
                d = max(d, self(u, v, adj) + 1);
            }
            return d;
        };

        int d = dfs(-1, 1, adj);
        return pow(2, d - 1, 1e9 + 7);
    }
};