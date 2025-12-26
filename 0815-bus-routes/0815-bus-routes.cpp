class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        unordered_map<int, vector<int>> toRoute; // bus stop -> route 

        for(int i = 0; i < n; i++) {
            for(int j : routes[i]) {
                // bus stop j can go to routes[i]
                toRoute[j].push_back(i);
            }
        }

        queue<array<int, 2>> q;
        unordered_set<int> seen; // seen bus stops
        unordered_set<int> seenr; // seen routes

        q.push({source, 0});
        while(!q.empty()) {
            auto [stop, buses] = q.front(); q.pop();

            if(stop == target) {
                return buses;
            }

            for(int r : toRoute[stop]) {
                if(seenr.find(r) != seenr.end()) {
                    continue;
                }
                seenr.insert(r);
                for(int nstop : routes[r]) {
                    if(seen.find(nstop) == seen.end()) {
                        seen.insert(nstop);
                        q.push({nstop, buses + 1});
                    }
                }

            }
        }

        return -1;
    }
};