class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, unordered_set<int>> idx; // x -> pos
        for(int i = 0; i < n; ++i) {
            idx[arr[i]].insert(i);
        }

        queue<array<int, 2>> q; // {idx, step}
        vector<bool> visited(n);
        q.push({0, 0});

        while(!q.empty()) {
            auto [i, s] = q.front();
            q.pop();

            if(i == n - 1) {
                return s;
            }

            int x = arr[i];
            for(int j : idx[x]) {
                if(!visited[j]) {
                    q.push({j, s + 1});
                    visited[j] = true;
                }
            }
            if(i + 1 < n && !visited[i + 1] && idx[x].count(i + 1) == 0) {
                q.push({i + 1, s + 1});
                visited[i + 1] = true;
            }
            if(i - 1 >= 0 && !visited[i - 1] && idx[x].count(i - 1) == 0) {
                q.push({i - 1, s + 1});
                visited[i - 1] = true;
            }

            idx[x].clear();
        }

        return -1;
    }
};