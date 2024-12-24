class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = diameter(edges1);
        int d2 = diameter(edges2);
        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }

    int diameter(const vector<vector<int>> &edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        vector<int> deg(n);

        for(const auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(deg[i] == 1) {
                q.push(i);
            }
        }

        int lvl = 0;
        while(n > 2) {
            n -= q.size();
            for(int i = q.size(); i > 0; i--) {
                int u = q.front();
                q.pop();
                for(int v : adj[u]) {
                    if(--deg[v] == 1) {
                        q.push(v);
                    }
                }
            }
            lvl++;
        }

        return n == 2 ? 2 * lvl + 1 : 2 * lvl;
    }
};