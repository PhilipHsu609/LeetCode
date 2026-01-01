class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(k-- >= 0) {
            vector<int> ndist(dist);
            for(const auto &f : flights) {
                if(dist[f[0]] != INT_MAX && dist[f[0]] + f[2] < ndist[f[1]]) {
                    ndist[f[1]] = dist[f[0]] + f[2];
                }
            }
            dist = ndist;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};