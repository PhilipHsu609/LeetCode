class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int n = graph.size();
        const int complete_mask = (1 << n) - 1;
        queue<array<int, 3>> q; // (current node, visited mask, path length)

        vector<unordered_set<int>> visited(n);

        // multi-source bfs
        for(int i = 0; i < n; ++i) {
            q.push({i, 1 << i, 0});
        }

        while(!q.empty()) {
            auto [u, mask, t] = q.front();
            q.pop();

            if(mask == complete_mask) {
                return t;
            }

            if(visited[u].count(mask) > 0) {
                continue;
            }

            for(int v : graph[u]) {
                int next_mask = mask | (1 << v);
                q.push({v, next_mask, t + 1});
            }
        }

        return -1;
    }
};