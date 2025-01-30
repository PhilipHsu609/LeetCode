class Solution {
public:
    // Theorem:
    //   A graph is bipartite iff it's two-colorable
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++) {
            for(int u : graph[i]) {
                adj[i].push_back(u);
                adj[u].push_back(i);
            }
        }

        // Use BFS to check if the graph is two-colorable
        queue<array<int, 2>> q;
        vector<int> color(n, -1); // 0, 1

        q.push({0, 0});

        while(!q.empty()) {
            auto [u, c] = q.front(); q.pop();

            if(color[u] != -1) {
                if(color[u] != c) {
                    return false;
                }
                continue;
            }

            color[u] = c;
            for(int v : adj[u]) {
                q.push({v, c == 0 ? 1 : 0});
            }
        }

        return true;
    }
};