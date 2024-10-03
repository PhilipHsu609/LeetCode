class Solution {
public:
    bool parseBoolExpr(string expression) {
        const string &expr = expression;
        int n = expr.length();
        return helper(expr, 0, n - 1);
    }

    bool helper(const string &expr, int start, int end) {
        vector<int> val;

        for(int i = start + 2; i <= end - 1; i++) {
            if(expr[i] == '!' || expr[i] == '&' || expr[i] == '|') {
                int level = 1;
                int j = i + 2;
                while(j <= end && level > 0) {
                    if(expr[j] == '(') {
                        level++;
                    }
                    if(expr[j] == ')') {
                        level--;
                    }
                    if(level == 0) {
                        break;
                    }
                    j++;
                }
                val.push_back(helper(expr, i, j) ? 1 : 0);
                i = j;    
            } else if(expr[i] == 't' || expr[i] == 'f') {
                val.push_back(expr[i] == 't' ? 1 : 0);
            }
        }

        return eval(expr[start], val);
    }

    bool eval(char op, const vector<int> &val) {
        if(op == '!') {
            return val[0] == 0;
        }
        if(op == '&') {
            int ret = 1;
            for(int v : val) {
                ret *= v;
            }
            return ret == 1;
        }
        if(op == '|') {
            int ret = 0;
            for(int v : val) {
                ret += v;
            }
            return ret != 0;
        }
        return false;
    }
};