class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;
    unordered_set<string> visited;

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();

        for(int i = 0; i < n; i++) {
            const auto &e = equations[i];
            adj[e[0]].push_back({e[1], values[i]});
            adj[e[1]].push_back({e[0], 1.0 / values[i]});
        }

        int q = queries.size();
        vector<double> ret(q);
        for(int i = 0; i < q; i++) {
            visited.clear();
            ret[i] = dfs(queries[i][0], queries[i][1]);
        }

        return ret;
    }

    double dfs(const string &start, const string &end) {
        if(adj.find(start) == adj.end()) {
            return -1.0;
        }

        if(start == end) {
            return 1.0;
        }

        double ret = -1.0;
        visited.insert(start);
        
        for(const auto &[next, w] : adj[start]) {
            if(visited.find(next) != visited.end()) {
                continue;
            }
            double remain = dfs(next, end);
            if(remain != -1.0) {
                ret = w * remain;
                break;
            }
        }

        return ret;
    }
};