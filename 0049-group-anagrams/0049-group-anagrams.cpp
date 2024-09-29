class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m; // {pattern, anagrams}
        for(string &s : strs) {
            string pat(26, 0);
            for(char c : s)
                pat[c - 'a']++;
            m[pat].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it : m)
            res.push_back(it.second);
        return res;
    }
};