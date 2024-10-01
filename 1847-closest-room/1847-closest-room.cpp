class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n = rooms.size();
        int k = queries.size();

        for(int i = 0; i < k; i++) {
            queries[i].push_back(i);
        }

        auto cmp = [](auto &a, auto &b) {
            return a[1] > b[1];
        };

        sort(rooms.begin(), rooms.end(), cmp);
        sort(queries.begin(), queries.end(), cmp);

        int i = 0;
        set<int> ids;
        vector<int> ret(k, -1);
        for(const auto &q : queries) {
            while(i < n && rooms[i][1] >= q[1]) {
                ids.insert(rooms[i][0]);
                i++;
            }

            int dist = INT_MAX;
            auto it = ids.lower_bound(q[0]);
            if(it != ids.end()) {
                if(*it - q[0] < dist) {
                    dist = *it - q[0];
                    ret[q[2]] = *it;
                }
            }

            if(it != ids.begin()) {
                it = prev(it, 1);
                if(q[0] - *it <= dist) {
                    ret[q[2]] = *it;
                }
            }
        }

        return ret;
    }
};