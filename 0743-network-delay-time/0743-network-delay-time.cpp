class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<array<int, 2>>> adj;

        for(const auto &t : times) {
            adj[t[0] - 1].push_back({t[1] - 1, t[2]});
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;

        pq.push({0, k - 1});
        dist[k - 1] = 0;

        while(!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();

            for(auto [v, w] : adj[u]) {
                if(t + w < dist[v]) {
                    dist[v] = t + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ret = 0;
        for(int d : dist) {
            if(d == INT_MAX) {
                return -1;
            }
            ret = max(ret, d);
        }

        return ret;
    }
};