class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();

        // Build graph for the chains
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            if(favorite[favorite[i]] != i) {
                adj[favorite[i]].push_back(i);
            }
        }

        // For every mutual favorite pair, sum the chains that connected to them
        int ret = 0;
        vector<bool> visited(n);
        for(int i = 0; i < n; i++) {
            if(favorite[favorite[i]] == i) {
                ret += dfs(i, adj, visited);
            }
        }

        // Check for loops, if the length of the loop is greater than ret, then it's the answer
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