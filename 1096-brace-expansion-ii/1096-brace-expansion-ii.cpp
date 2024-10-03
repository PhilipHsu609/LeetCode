class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        string &expr = expression;
        int n = expr.length();
        auto s = dfs(expr, 0, n - 1);

        vector<string> ret(s.begin(), s.end());
        sort(ret.begin(), ret.end());
        return ret;
    }

    unordered_set<string> dfs(const string &expr, int start, int end) {
        stack<unordered_set<string>> st;
        unordered_set<string> cur;

        for(int i = start; i <= end; i++) {
            if(expr[i] == '{') {
                int j = i + 1;
                int level = 1;
                while(j <= end && level > 0) {
                    if(expr[j] == '{') {
                        level++;
                    }
                    if(expr[j] == '}') {
                        level--;
                    }
                    if(level == 0) {
                        break;
                    }
                    j++;
                }
                auto next = dfs(expr, i + 1, j - 1);
                cur = product(cur, next);
                i = j;
            } else if(expr[i] == ',') {
                st.push(cur);
                cur.clear();
            } else {
                // alphabets
                int j = i + 1;
                while(j <= end && isalpha(expr[j])) {
                    j++;
                }

                unordered_set<string> next{expr.substr(i, j - i)};
                cur = product(cur, next);
                i = j - 1;
            }
        }

        while(!st.empty()) {
            for(const auto &s : st.top()) {
                cur.insert(s);
            }
            st.pop();
        }

        return cur;
    }

    unordered_set<string> product(unordered_set<string> &a, unordered_set<string> &b) {
        unordered_set<string> ret;
        if(a.empty()) {
            a.insert("");
        }
        for(const auto &x : a) {
            for(const auto &y : b) {
                ret.insert(x + y);
            }
        }
        return ret;
    }
};