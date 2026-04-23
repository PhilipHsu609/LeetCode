class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        unordered_map<int, vector<long long>> prefix;
        vector<int> idx(n);
        vector<long long> ret(n);

        for(int i = 0; i < n; ++i) {
            idx[i] = ++cnt[nums[i]];
            if(prefix[nums[i]].empty()) {
                prefix[nums[i]].push_back(0);
            }
            prefix[nums[i]].push_back(prefix[nums[i]].back() + i);
        }

        for(int i = 0; i < n; ++i) {
            int l = idx[i] - 1;
            if(l > 0) {
                ret[i] = 1LL * i * l - prefix[nums[i]][l];
            }
            int r = cnt[nums[i]] - l - 1;
            if(r > 0) {
                ret[i] += (prefix[nums[i]].back() - prefix[nums[i]][l + 1]) - 1LL * i * r;
            }
        }

        return ret;
    }
};
