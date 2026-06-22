class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> v;

        for(int i = 0; i < chars.size(); ++i) {
            v[chars[i]] = vals[i];
        }

        int cost = 0;
        int ret = 0;
        for(char ch : s) {
            int cc = ch - 'a' + 1;
            if(v.find(ch) != v.end()) {
                cc = v[ch];
            }
            cost = max(0, cost + cc);
            ret = max(ret, cost);
        }

        return ret;
    }
};