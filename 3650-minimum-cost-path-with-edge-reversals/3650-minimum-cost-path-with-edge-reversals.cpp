class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);

        for(const auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], 2 * e[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();

            if(u == n - 1) {
                return w;
            }

            if(dist[u] < w) {
                continue;
            }

            for(auto [v, m] : adj[u]) {
                if(dist[v] > w + m) {
                    dist[v] = w + m;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1;
    }
};