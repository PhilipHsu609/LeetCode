class Solution {
public:
    string reverseParentheses(string s) {
        return helper(s, 0, s.length() - 1);
    }

    string helper(const string &s, int start, int end) {
        string ret;

        for(int i = start; i <= end; i++) {
            if(s[i] == '(') {
                int j = i + 1;
                int level = 1;
                while(j <= end && level > 0) {
                    if(s[j] == '(') {
                        level++;
                    }
                    if(s[j] == ')') {
                        level--;
                    }
                    if(level == 0) {
                        break;
                    }
                    j++;
                }
                string rev = helper(s, i + 1, j - 1);
                reverse(rev.begin(), rev.end());
                ret += rev;
                i = j;
            } else {
                ret += s[i];
            }
        }

        return ret;
    }
};