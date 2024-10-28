class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int, int> m;

        for(int n : nums) {
            m[n] = 1;
        }

        int ret = 1;
        for(auto [k, v] : m) {
            if(k > INT_MAX / k) {
                continue;
            }

            int sq = k * k;
            if(m.find(sq) != m.end()) {
                m[sq] = v + 1;
            }

            ret = max(ret, v);
        }

        return ret == 1 ? -1 : ret;
    }
};