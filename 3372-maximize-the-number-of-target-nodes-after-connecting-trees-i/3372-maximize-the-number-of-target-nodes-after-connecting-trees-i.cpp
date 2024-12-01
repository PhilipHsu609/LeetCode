class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);

        for(const auto &e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }

        for(const auto &e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        auto cnt1 = bfs(adj1, k);
        auto cnt2 = bfs(adj2, k - 1);

        int mt = *max_element(begin(cnt2), end(cnt2));
        for_each(begin(cnt1), end(cnt1), [mt](int &x) {
            x += mt;
        });

        return cnt1;
    }

    vector<int> bfs(const vector<vector<int>> &adj, int k) {
        int n = adj.size();
        vector<int> cnt(n);

        for(int i = 0; i < n; i++) {
            int d = k;
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(i);

            while(!q.empty() && d >= 0) {
                for(int s = q.size(); s > 0; s--) {
                    int u = q.front(); q.pop();
                    visited[u] = true;
                    cnt[i]++;

                    for(int v : adj[u]) {
                        if(!visited[v]) {
                            q.push(v);
                        }
                    }
                }
                d--;
            }
        }

        return cnt;
    }
};