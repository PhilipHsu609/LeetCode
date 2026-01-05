class Solution {
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> adj(n);

        for(const auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ret = 0;
        helper(adj, cost, -1, 0, ret);
        return ret;
    }

    long long helper(const vector<vector<int>> &adj, const vector<int> &cost, int p, int u, int &ret) {
        long long maxi = 0;
        int cnt = 0;

        for(int v : adj[u]) {
            if(v == p) {
                continue;
            }
            long long sum = helper(adj, cost, u, v, ret);
            if(sum == maxi) {
                ++cnt;
            } else if(sum > maxi) {
                maxi = sum;
                cnt = 1;
            }
        }

        if(cnt != 0) {
            ret += adj[u].size() - cnt - static_cast<int>(u != 0);
        }

        return maxi + cost[u];
    }
};