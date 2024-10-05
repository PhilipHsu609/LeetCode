class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<array<int, 2>> ps;

        for(int i = 0; i < n; i++) {
            ps.push_back({position[i], speed[i]});
        }

        sort(ps.begin(), ps.end());

        int ret = 0;
        float maxTime = 0.0f;
        for(int i = n - 1; i >= 0; i--) {
            if(static_cast<float>(target - ps[i][0]) / ps[i][1] > maxTime) {
                maxTime = static_cast<float>(target - ps[i][0]) / ps[i][1];
                ret++;
            }
        }

        return ret;
    }
};