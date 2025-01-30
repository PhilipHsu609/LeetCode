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
        queue<int> q;
        vector<int> color(n, -1); // 0, 1

        for(int s = 0; s < n; s++) {
            if(color[s] != -1) {
                continue;
            }

            q.push(s);
            color[s] = 0;

            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(int v : adj[u]) {
                    if(color[v] == -1) {
                        color[v] = color[u] ^ 1;
                        q.push(v);
                    } else if(color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};