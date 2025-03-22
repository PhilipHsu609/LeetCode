class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(const auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n);
        vector<vector<int>> component;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                component.emplace_back();
                dfs(i, visited, component, adj);
            }
        }

        int ret = 0;
        for(const auto &comp : component) {
            bool complete = true;
            for(int u : comp) {
                if(adj[u].size() != comp.size() - 1) {
                    complete = false;
                    break;
                }
            }
            if(complete) {
                ret++;
            }
        }

        return ret;
    }

    void dfs(int u, vector<bool> &visited, vector<vector<int>> &component, const vector<vector<int>> &adj) {
        visited[u] = true;
        component.back().push_back(u);

        for(int v : adj[u]) {
            if(!visited[v]) {
                dfs(v, visited, component, adj);
            }
        }
    }
};