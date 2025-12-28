class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) {
            return {0};
        }
        vector<int> deg(n, 0);
        unordered_map<int, vector<int>> adj;

        for(const auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }

        vector<int> ret;
        for(int i = 0; i < n; i++) {
            if(deg[i] == 1) {
                ret.push_back(i);
            }
        }

        while(n > 2) {
            n -= ret.size();
            vector<int> tmp;
            for(int u : ret) {
                for(int v : adj[u]) {
                    if(--deg[v] == 1) {
                        tmp.push_back(v);
                    }
                }
            }
            ret = tmp;
        }

        return ret;
    }
};