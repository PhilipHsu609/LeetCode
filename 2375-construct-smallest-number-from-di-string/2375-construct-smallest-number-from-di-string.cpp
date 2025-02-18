class Solution {
public:
    string smallestNumber(string pattern) {
        string ret;
        helper(pattern, 0, 0, ret);
        reverse(ret.begin(), ret.end());
        return ret;
    }

    int helper(const string &pattern, int idx, int cnt, string &ret) {
        if(idx != pattern.length()) {
            if(pattern[idx] == 'I') {
                helper(pattern, idx + 1, idx + 1, ret);
            } else {
                cnt = helper(pattern, idx + 1, cnt, ret);
            }
        }
        ret += to_string(cnt + 1);
        return cnt + 1;
    }
};