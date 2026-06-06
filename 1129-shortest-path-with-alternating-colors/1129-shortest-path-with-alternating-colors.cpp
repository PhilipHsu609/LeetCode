class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> adjR(n), adjB(n);

        for(const auto &e : redEdges) {
            adjR[e[0]].push_back(e[1]);
        }

        for(const auto &e : blueEdges) {
            adjB[e[0]].push_back(e[1]);
        }

        vector<vector<int>> dis(2, vector<int>(n, INT_MAX));
        queue<array<int, 2>> q; // {node, isRed}

        dis[0][0] = dis[1][0] = 0;
        q.push({0, 0});
        q.push({0, 1});

        while(!q.empty()) {
            auto [u, isRed] = q.front();
            q.pop();

            const auto &adj = [&]() {
                return isRed ? adjB : adjR;
            }();

            for(int v : adj[u]) {
                if(dis[1 - isRed][v] != INT_MAX) {
                    continue;
                }
                dis[1 - isRed][v] = dis[isRed][u] + 1;
                q.push({v, 1 - isRed});
            }
        }

        vector<int> ret(n);
        for(int i = 0; i < n; ++i) {
            ret[i] = min(dis[0][i], dis[1][i]);
            if(ret[i] == INT_MAX) {
                ret[i] = -1;
            }
        }

        return ret;
    }
};