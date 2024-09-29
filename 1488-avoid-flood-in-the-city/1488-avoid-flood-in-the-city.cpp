class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        unordered_map<int, int> m; // lake i -> last day filled lake i
        set<int> s; // indices of i where rains[i] == 0
        vector<int> ret(n, 1);

        for(int i = 0; i < n; i++) {
            if(rains[i] == 0) {
                s.insert(i);
                continue;
            }

            ret[i] = -1;
            if(m.find(rains[i]) != m.end()) {
                // rains[i] has been filled before
                int j = m[rains[i]];
                auto dry = s.upper_bound(j);

                if(dry == s.end()) {
                    return {};
                }

                ret[*dry] = rains[i]; // we dry rains[i] at *dry
                s.erase(dry);
            }

            m[rains[i]] = i;
        }

        return ret;
    }
};