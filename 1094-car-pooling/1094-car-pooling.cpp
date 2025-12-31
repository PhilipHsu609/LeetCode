class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> diff;

        for(const auto &t : trips) {
            diff[t[1]] += t[0];
            diff[t[2]] -= t[0];
        }

        int prefix = 0;
        for(auto [k, v] : diff) {
            prefix += v;
            if(prefix > capacity) {
                return false;
            }
        }

        return true;
    }
};