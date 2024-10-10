class Solution {
public:
    int time = 0;
    vector<int> dfn, low, visited;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        dfn.resize(n);
        low.resize(n);
        visited.resize(n);

        vector<vector<int>> adj(n);

        for(const auto &e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<vector<int>> ret;

        dfs(0, -1, adj, ret);

        return ret;
    }

    void dfs(int u, int p, const vector<vector<int>> &adj, vector<vector<int>> &ret) {
        dfn[u] = low[u] = time++;
        visited[u] = 1;

        for(int v : adj[u]) {
            if(v == p) {
                continue;
            }

            if(visited[v] == 0) {
                dfs(v, u, adj, ret);

                if(low[v] > dfn[u]) {
                    ret.push_back({u, v});
                }

                low[u] = min(low[u], low[v]);
            } else {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
};