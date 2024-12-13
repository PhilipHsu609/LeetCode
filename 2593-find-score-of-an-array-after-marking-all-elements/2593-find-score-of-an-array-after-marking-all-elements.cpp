class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<array<int, 2>> ni;

        for(int i = 0; i < n; i++) {
            ni.push_back({nums[i], i});
        }

        sort(begin(ni), end(ni));

        unordered_set<int> marked;
        long long ret = 0;
        for(int i = 0; i < n; i++) {
            if(marked.find(ni[i][1]) != marked.end()) {
                continue;
            }

            ret += ni[i][0];
            marked.insert(ni[i][1] + 1);
            marked.insert(ni[i][1] - 1);
        }

        return ret;
    }
};