class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<array<int, 3>> times;

        for(const auto &e : events) {
            times.push_back({e[0], 1, e[2]});
            times.push_back({e[1] + 1, 0, e[2]});
        }

        sort(begin(times), end(times));

        int ret = 0;
        int maxi= 0 ;
        for(auto [t, start, v] : times) {
            if(start == 1) {
                ret = max(ret, maxi + v);
            } else {
                maxi = max(maxi, v);
            }
        }

        return ret;
    }
};