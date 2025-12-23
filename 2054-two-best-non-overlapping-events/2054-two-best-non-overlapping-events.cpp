class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<array<int, 3>> times;

        for(const auto &e : events) {
            times.push_back({e[1] + 1, 0, e[2]}); // end time first
            times.push_back({e[0], 1, e[2]}); // start time second
        }

        sort(times.begin(), times.end());

        int ret = 0;
        int maxv = 0;
        for(auto [t, s, v] : times) {
            if(s == 1) {
                // start time
                // try to pick this event
                ret = max(ret, maxv + v);
            } else {
                // end time
                // we reach the end of an event
                // which ensures that the rest of the starting events wont overlap with the previous events
                maxv = max(maxv, v);
            }
        }

        return ret;
    }
};
