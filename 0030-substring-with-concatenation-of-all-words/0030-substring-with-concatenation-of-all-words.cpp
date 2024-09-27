class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> count;

        for(const auto &w : words) {
            count[w]++;
        }

        int ns = s.length(), nw = words[0].length(), m = words.size();
        vector<int> ret;

        int i = 0;
        while(i < ns - nw * m + 1) {
            int j = 0;
            unordered_map<string, int> seen;
            while(j < m) {
                string w = s.substr(i + j * nw, nw);
                seen[w]++;
                if(count.find(w) == count.end() || seen[w] > count[w]) {
                    break;
                }
                j++;
            }

            if(j == m) {
                ret.push_back(i);
            }
            i += nw;
        }

        return ret;
    }
};