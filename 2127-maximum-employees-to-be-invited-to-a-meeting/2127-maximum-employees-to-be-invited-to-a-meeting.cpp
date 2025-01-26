class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();

        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            if(favorite[favorite[i]] != i) {
                adj[favorite[i]].push_back(i);
            }
        }

        int ret = 0;
        vector<bool> visited(n);
        for(int i = 0; i < n; i++) {
            if(favorite[favorite[i]] == i) {
                ret += dfs(i, adj, visited);
            }
        }

        // Check for loops
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            int j = i;

            while(!visited[j]) {
                visited[j] = true;
                cnt++;
                j = favorite[j];
            }

            for(int k = i; k != j; k = favorite[k]) {
                cnt--;
            }

            ret = max(ret, cnt);
        }

        return ret;
    }

    int dfs(int u, const vector<vector<int>> &adj, vector<bool> &visited) {
        visited[u] = true;

        int ret = 0;
        for(int v : adj[u]) {
            ret = max(ret, dfs(v, adj, visited));
        }

        return ret + 1;
    }
};