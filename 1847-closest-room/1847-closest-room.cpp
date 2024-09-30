class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n = rooms.size(), k = queries.size();

        for(int i = 0; i < k; i++) {
            queries[i].push_back(i);
        }

        auto cmp = [](auto &a, auto &b) {
            return a[1] > b[1];
        };

        sort(rooms.begin(), rooms.end(), cmp);
        sort(queries.begin(), queries.end(), cmp);

        int i = 0;
        set<int> s; // room ids that satisfied the query
        vector<int> ret(k);
        for(const auto &q : queries) {
            while(i < n && rooms[i][1] >= q[1]) {
                s.insert(rooms[i][0]);
                i++;
            }

            auto it = s.lower_bound(q[0]);
            int dist = INT_MAX;
            int id = -1;

            if(it != s.end()) {
                if(*it - q[0] < dist) {
                    dist = *it - q[0];
                    id = *it;
                }
            }

            if(it != s.begin()) {
                it = prev(it, 1);
                if(abs(*it - q[0]) <= dist) {
                    dist = abs(*it - q[0]);
                    id = *it;
                }
            }

            ret[q[2]] = id;
        }

        return ret;
    }
};