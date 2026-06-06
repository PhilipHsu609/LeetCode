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
        vector<int> ret(n, -1);
        queue<array<int, 2>> q; // {node, isRed}

        dis[0][0] = dis[1][0] = 0;
        q.push({0, 0});
        q.push({0, 1});

        while(!q.empty()) {
            auto [u, isRed] = q.front();
            q.pop();

            if(ret[u] == -1) {
                ret[u] = min(dis[0][u], dis[1][u]);
            }

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

        return ret;
    }
};