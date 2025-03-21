class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> adj;
        unordered_set<string> sup;

        for(const auto &s : supplies) {
            sup.insert(s);
        }

        unordered_map<string, int> indeg;
        for(const auto &r : recipes) {
            indeg[r] = 0;
        }

        int n = recipes.size();
        for(int i = 0; i < n; i++) {
            for(const auto &in : ingredients[i]) {
                if(sup.find(in) == sup.end()) {
                    adj[in].push_back(recipes[i]);
                    indeg[recipes[i]]++;
                }
            }
        }

        queue<string> q;
        for(const auto &r : recipes) {
            if(indeg[r] == 0) {
                q.push(r);
            }
        }

        vector<string> ret;
        while(!q.empty()) {
            string u = q.front();
            q.pop();
            ret.push_back(u);
            for(const auto &v : adj[u]) {
                if(--indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        return ret;
    }
};