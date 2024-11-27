class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dist(n);
        vector<int> ret;
        vector<vector<int>> adj(n);

        for(int i = 0; i < n - 1; i++) {
            dist[i + 1] = i + 1;
            adj[i].push_back(i + 1);
        }

        for(const auto &query : queries) {
            adj[query[0]].push_back(query[1]);

            if(dist[query[0]] + 1 >= dist[query[1]]) {
                ret.push_back(dist[n - 1]);
                continue;
            }

            dist[query[1]] = dist[query[0]] + 1;
            for(int u = query[1]; u < n; u++) {
                for(int v : adj[u]) {
                    dist[v] = min(dist[v], dist[u] + 1);
                }
            }

            ret.push_back(dist[n - 1]);
        }

        return ret;
    }
};