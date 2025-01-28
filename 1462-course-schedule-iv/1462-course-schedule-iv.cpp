class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;

        vector<vector<int>> adj(n);
        for(const auto &p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }

        vector<vector<bool>> visited(n, vector<bool>(n));
        for(int i = 0; i < n; i++) {
            dfs(i, adj, visited[i]);
        }

        vector<bool> ret;
        for(const auto &q : queries) {
            ret.push_back(visited[q[0]][q[1]]);
        }

        return ret;
    }

    void dfs(int u, const vector<vector<int>> &adj, vector<bool> &visited) {
        if(visited[u]) {
            return;
        }
        visited[u] = true;
        for(int v : adj[u]) {
            dfs(v, adj, visited);
        }
    }
};