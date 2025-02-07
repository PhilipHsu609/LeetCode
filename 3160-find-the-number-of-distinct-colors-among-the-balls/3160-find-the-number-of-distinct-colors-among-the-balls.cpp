class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colors;
        vector<int> ret;
        unordered_map<int, int> cnt;

        for(const auto &q : queries) {
            if(colors[q[0]] != 0) {
                if(--cnt[colors[q[0]]] == 0) {
                    cnt.erase(colors[q[0]]);
                }
            }
            colors[q[0]] = q[1];
            cnt[q[1]]++;

            ret.push_back(cnt.size());
        }

        return ret;
    }
};