class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(const auto &e : edges) {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }

        vector<int> color(n, -1);
        queue<int> q;

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
                        // The graph is not a bipartite, the valid splits do not exist
                        return -1;
                    }
                }
            }
        }

        vector<int> dist(n);
        for(int i = 0; i < n; i++) {
            dist[i] = lsdist(adj, i);
        }

        int ret = 0;
        vector<bool> visited(n);
        for(int i = 0; i < n; i++) {
            if(visited[i]) {
                continue;
            }

            ret += getGroup(adj, i, dist, visited);
        }

        return ret;
    }

    // Longest shortest distance
    int lsdist(const vector<vector<int>> &adj, int s) {
        int n = adj.size();
        int ret = 0;
        vector<bool> visited(n);
        queue<int> q;

        q.push(s);
        visited[s] = true;

        while(!q.empty()) {
            for(int i = q.size(); i > 0; i--) {
                int u = q.front(); q.pop();
                for(int v : adj[u]) {
                    if(!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            ret++;
        }

        return ret;
    }

    int getGroup(const vector<vector<int>> &adj, int s, const vector<int> &dist, vector<bool> &visited) {
        int ret = dist[s];
        visited[s] = true;
        
        for(int v : adj[s]) {
            if(!visited[v]) {
                ret = max(ret, getGroup(adj, v, dist, visited));
            }
        }

        return ret;
    }
};