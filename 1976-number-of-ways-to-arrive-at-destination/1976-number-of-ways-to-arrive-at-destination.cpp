class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        vector<vector<array<int, 2>>> adj(n);

        for(const auto &e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n);

        ways[0] = 1;
        dist[0] = 0;

        priority_queue<array<long long, 2>, vector<array<long long, 2>>, greater<array<long long, 2>>> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            if(d > dist[u]) {
                continue;
            }

            for(auto [v, w] : adj[u]) {
                if(dist[v] > d + w) {
                    dist[v] = d + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                } else if(dist[v] == d + w) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};