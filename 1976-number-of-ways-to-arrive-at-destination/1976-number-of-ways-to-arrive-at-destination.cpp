class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        vector<vector<array<int, 2>>> adj(n);

        for(const auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        priority_queue<array<long long, 2>, vector<array<long long, 2>>, greater<array<long long, 2>>> pq;

        vector<long long> time(n, LLONG_MAX);
        vector<int> ways(n);

        pq.push({0, 0});
        ways[0] = 1;
        time[0] = 0;

        while(!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();

            if(t > time[u]) {
                continue;
            }

            for(auto [v, w] : adj[u]) {
                if(t + w < time[v]) {
                    time[v] = t + w;
                    ways[v] = ways[u];
                    pq.push({t + w, v});
                } else if(t + w == time[v]) {
                    ways[v] += ways[u];
                    ways[v] %= MOD;
                }
            }
        }

        return ways[n - 1];
    }
};