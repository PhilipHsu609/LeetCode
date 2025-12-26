class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indeg(n);

        for(const auto &pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            ++indeg[pre[0]];
        }

        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ++cnt;

            for(int v : adj[u]) {
                if(--indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        return cnt == n;
    }
};