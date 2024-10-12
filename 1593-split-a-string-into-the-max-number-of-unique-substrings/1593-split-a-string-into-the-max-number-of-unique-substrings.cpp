class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> cur;
        return helper(0, s, cur);
    }

    int helper(int idx, const string &s, unordered_set<string> &cur) {
        int n = s.length();
        if(idx == n) {
            return cur.size();
        }

        int ret = 0;
        for(int i = idx; i < n; i++) {
            string sub = s.substr(idx, i - idx + 1);

            if(cur.find(sub) != cur.end()) {
                continue;
            }

            cur.insert(sub);
            ret = max(ret, helper(i + 1, s, cur));
            cur.erase(sub);
        }

        return ret;
    }
};