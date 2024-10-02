class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int ret = 0;
        stack<int> stk;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                stk.push(i);
            } else {
                if(!stk.empty() && s[stk.top()] == '(') {
                    stk.pop();

                    ret = max(ret, i - (stk.empty() ? -1 : stk.top()));
                } else {
                    stk.push(i);
                }
            }
        }

        return ret;
    }
};