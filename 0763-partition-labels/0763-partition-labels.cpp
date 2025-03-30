class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        unordered_map<char, int> m;

        for(int i = 0; i < n; i++) {
            m[s[i]] = i;
        }

        int start = 0, end = 0;
        vector<int> ret;
        for(int i = 0; i < n; i++) {
            end = max(end, m[s[i]]);

            if(i == end) {
                ret.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return ret;
}
};