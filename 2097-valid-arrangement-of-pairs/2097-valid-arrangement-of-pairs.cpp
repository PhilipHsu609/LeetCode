class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indeg, outdeg;

        for(const auto &p : pairs) {
            adj[p[0]].push_back(p[1]);

            indeg[p[1]]++;
            outdeg[p[0]]++;
        }

        stack<int> st;
        vector<int> path;
        vector<vector<int>> ret;

        int start = pairs[0][0];
        for(auto &[u, _] : adj) {
            if(outdeg[u] - indeg[u] == 1) {
                start = u;
                break;
            }
        }

        st.push(start);

        while(!st.empty()) {
            int u = st.top();

            while(!adj[u].empty()) {
                int v = adj[u].back();
                adj[u].pop_back();
                
                st.push(v);
                u = v;
            }

            path.push_back(st.top());
            st.pop();
        }

        int n = path.size();
        for(int i = n - 2; i >= 0; i--) {
            ret.push_back({path[i + 1], path[i]});
        }

        return ret;
    }
};