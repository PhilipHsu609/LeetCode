class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for(int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        for(const auto &e : edges) {
            if(e[2] > distanceThreshold) {
                continue;
            }
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) {
                        continue;
                    } 
                    int nxt = dist[i][k] + dist[k][j];
                    if(nxt <= distanceThreshold && nxt < dist[i][j]) {
                        dist[i][j] = nxt;
                    }
                }
            }
        }

        int ret = -1;
        int mincnt = n;
        for(int i = 0; i < n; ++i) {
            int cnt = 0;
            for(int j = 0; j < n; ++j) {
                cnt += static_cast<int>(dist[i][j] != INT_MAX);
            }
            if(cnt <= mincnt) {
                mincnt = cnt;
                ret = i;
            }
        }

        return ret;
    }
};