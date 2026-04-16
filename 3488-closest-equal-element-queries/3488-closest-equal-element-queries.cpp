class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> idx;

        for(int i = 0; i < n; ++i) {
            idx[nums[i]].push_back(i);
        }

        vector<int> ret;
        for(int i : queries) {
            int m = idx[nums[i]].size();
            if(m <= 1) {
                ret.push_back(-1);
                continue;
            }

            auto it = lower_bound(idx[nums[i]].begin(), idx[nums[i]].end(), i);
            int j = distance(idx[nums[i]].begin(), it);

            int l = idx[nums[i]][((j - 1) % m + m) % m];
            int r = idx[nums[i]][(j + 1) % m];
            int dis = min(
                min(abs(i - l), n - abs(i - l)),
                min(abs(i - r), n - abs(i - r))
            );

            ret.push_back(dis);
        }

        return ret;
    }
};