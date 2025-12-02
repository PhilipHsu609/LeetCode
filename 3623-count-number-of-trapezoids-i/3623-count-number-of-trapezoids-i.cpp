class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int MOD = 1e9 + 7;
        unordered_map<int, int> yaxis;

        for(const auto &p : points) {
            yaxis[p[1]]++;
        }

        int ret = 0;
        int seen = 0;
        for(const auto [k, v] : yaxis) {
            long long provide = ((v * static_cast<long long>(v - 1)) / 2) % MOD;
            long long add = (seen * provide) % MOD;
            
            ret = (ret + static_cast<int>(add)) % MOD;
            seen = (seen + static_cast<int>(provide)) % MOD;
        }
        return ret;
    }
};