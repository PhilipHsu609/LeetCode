class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = vals.size();
        unordered_map<char, int> costs;

        for(int i = 0; i < n; ++i) {
            costs[chars[i]] = vals[i];
        }

        int ret = 0;
        int cur = 0;
        for(char ch : s) {
            int cost = 0;
            if(costs.find(ch) == costs.end()) {
                cost = ch - 'a' + 1;
            } else {
                cost = costs[ch];
            }

            cur = max(cost, cur + cost);
            ret = max(ret, cur);
        }

        return ret;
    }
};