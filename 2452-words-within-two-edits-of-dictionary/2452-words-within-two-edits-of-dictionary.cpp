class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        int m = queries[0].size();
        vector<string> ret;
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        for(int i = 0; i < n; ++i) {
            for(const auto &s : dict) {
                int diff = 0;
                for(int j = 0; j < m; ++j) {
                    if(queries[i][j] != s[j]) {
                        ++diff;
                    }
                }
                if(diff < 3) {
                    ret.push_back(queries[i]);
                    break;
                }
            }
        }
        
        return ret;
    }
};