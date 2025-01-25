class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<array<int, 2>> numi(n);

        for(int i = 0; i < n; i++) {
            numi[i] = {nums[i], i};
        }

        sort(begin(numi), end(numi));

        vector<vector<int>> groups; // group of indices
        for(int i = 0; i < n; i++) {
            if(i == 0 || numi[i][0] - numi[i - 1][0] > limit) {
                // new group
                groups.emplace_back();
            }
            groups.back().push_back(numi[i][1]);
        }

        vector<int> ret(n);
        for(const auto &g : groups) {
            vector<int> sg(g);
            sort(begin(sg), end(sg));

            for(int i = 0; i < g.size(); i++) {
                ret[sg[i]] = nums[g[i]];
            }
        }

        return ret;
    }
};