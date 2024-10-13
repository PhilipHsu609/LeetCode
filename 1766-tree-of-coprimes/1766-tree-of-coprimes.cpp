class Solution {
public:
    unordered_map<int, vector<int>> coprimes;
    unordered_map<int, vector<array<int, 2>>> paths; // {level, idx}

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());

        for(int a : s) {
            for(int b : s) {
                if(gcd(a, b) == 1) {
                    coprimes[a].push_back(b);
                }
            }
        }

        vector<int> ret(n, -1);
        vector<vector<int>> adj(n);
        for(const auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(nums, adj, 0, -1, 0, ret);

        return ret;
    }

    void dfs(const vector<int> &nums, const vector<vector<int>> &adj, int u, int p, int level, vector<int> &ret) {
        int maxLevel = -1;
        for(int coprime : coprimes[nums[u]]) {
            if(!paths[coprime].empty() && paths[coprime].back()[0] > maxLevel) {
                maxLevel = paths[coprime].back()[0];
                ret[u] = paths[coprime].back()[1];
            }
        }

        paths[nums[u]].push_back({level, u});

        for(int v : adj[u]) {
            if(v == p) {
                continue;
            }
            dfs(nums, adj, v, u, level + 1, ret);
        }

        paths[nums[u]].pop_back();
    }
};