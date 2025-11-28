class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);

        for(const auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        function<int(int, int, int&)> dfs = [&](int cur, int prev, int &com) {
            int sum = values[cur];
            for(int v : adj[cur]) {
                if(v == prev) {
                    continue;
                }
                int vsum = dfs(v, cur, com);

                if(vsum % k == 0) {
                    com++;
                } else {
                    sum = (sum + vsum) % k;
                }
            }
            return sum;
        };

        int ret = 0;
        int sum = dfs(0, -1, ret);
        ret += static_cast<int>(sum % k == 0);

        return ret;
    }
};

/*

def dfs(node, numComponents)
    sum of left = visit left
    sum of right = visit right

    eval node {
        if sum of left % k == 0
            We found a new components
        else
            node value += sum of left
        if sum of right % k == 0
            We found a new components
        else
            node value += sum of right
    }

    return noe value
*/