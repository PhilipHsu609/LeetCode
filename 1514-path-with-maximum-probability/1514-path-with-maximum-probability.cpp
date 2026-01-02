class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;

        for(int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq;
        vector<double> prob(n, 0.0);

        prob[start_node] = 1.0;
        pq.push({1.0, start_node});

        while(!pq.empty()) {
            auto [p, u] = pq.top();
            pq.pop();

            if(u == end_node) {
                return p;
            }

            if(p < prob[u]) {
                continue;
            }

            for(auto [v, w] : adj[u]) {
                if(p * w > prob[v]) {
                    prob[v] = p * w;
                    pq.push({prob[v], v});
                }
            }
        }

        return 0;
    }
};