class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> dist;

        for(int i = 0; i < n; ++i) {
            dist[nums[i]].push_back(i);
        }

        int ret = INT_MAX;
        for(auto &[k, v] : dist) {
            if(v.size() < 3) {
                continue;
            }
            sort(v.begin(), v.end());

            for(int i = 2; i < v.size(); ++i) {
                int d = abs(v[i - 2] - v[i - 1]) + abs(v[i - 1] - v[i]) + abs(v[i - 2] - v[i]);
                ret = min(ret, d);
            }
        }

        return ret == INT_MAX ? -1 : ret;
    }
};