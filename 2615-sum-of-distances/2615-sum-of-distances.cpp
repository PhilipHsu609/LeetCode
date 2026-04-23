class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> idx;
        vector<long long> ret(n);

        for(int i = 0; i < n; ++i) {
            idx[nums[i]].push_back(i);
        }

        unordered_map<int, vector<long long>> prefix;
        for(const auto &[k, v] : idx) {
            prefix[k].resize(v.size() + 1);
            for(int i = 1; i <= v.size(); ++i) {
                prefix[k][i] = prefix[k][i - 1] + idx[k][i - 1];
            }
        }

        for(int i = 0; i < n; ++i) {
            auto it = lower_bound(idx[nums[i]].begin(), idx[nums[i]].end(), i);
            int l = std::distance(idx[nums[i]].begin(), it);
            if(l > 0) {
                ret[i] = 1LL * i * l - prefix[nums[i]][l];
            }
            int r = idx[nums[i]].size() - l - 1;
            if(r > 0) {
                ret[i] += (prefix[nums[i]].back() - prefix[nums[i]][l + 1]) - 1LL * i * r;
            }
        }

        return ret;
    }
};
