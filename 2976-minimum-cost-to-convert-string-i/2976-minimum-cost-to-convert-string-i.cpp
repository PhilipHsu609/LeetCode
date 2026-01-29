class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.length();
        int m = cost.size();
        int nodes = 26;

        vector<vector<int>> dist(nodes, vector<int>(nodes, INT_MAX));
        for(int i = 0; i < m; ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int c = cost[i];

            dist[u][u] = dist[v][v] = 0;
            dist[u][v] = min(dist[u][v], c);
        }

        for(int k = 0; k < nodes; ++k) {
            for(int u = 0; u < nodes; ++u) {
                for(int v = 0; v < nodes; ++v) {
                    if(dist[u][k] == INT_MAX || dist[k][v] == INT_MAX) {
                        continue;
                    }
                    if(dist[u][k] + dist[k][v] < dist[u][v]) {
                        dist[u][v] = dist[u][k] + dist[k][v];
                    }
                }
            }
        }

        long long ret = 0;
        for(int i = 0; i < n; ++i) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if(dist[u][v] == INT_MAX) {
                return -1;
            }

            ret += dist[u][v];
        }

        return ret;
    }
};