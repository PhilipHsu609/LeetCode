class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for(const auto &t : tickets) {
            adj[t[0]].push(t[1]);
        }

        stack<string> s;
        vector<string> path;

        s.push("JFK");
        while(!s.empty()) {
            while(!adj[s.top()].empty()) {
                string v = adj[s.top()].top();
                adj[s.top()].pop();
                s.push(v);
            }
            path.push_back(s.top());
            s.pop();
        }

        reverse(path.begin(), path.end());
        return path;
    }
};