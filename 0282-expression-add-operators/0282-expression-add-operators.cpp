class Solution {
public:
    string num;
    int target;
    vector<string> ret;

    vector<string> addOperators(string num, int target) {
        this->num = num;
        this->target = target;

        dfs(0, "", 0, 0);

        return ret;
    }

    void dfs(int idx, const string &expr, long long sum, long long prevNum) {
        if(idx == num.length()) {
            if(sum == target) {
                ret.push_back(expr);
            }
            return;
        }

        long long curNum = 0;
        string curNumS = "";
        for(int i = idx; i < num.length(); i++) {
            if(i > idx && num[idx] == '0') {
                // num[idx:] = 0...
                // skip leading zero
                break;
            }

            curNum = curNum * 10 + (num[i] - '0');
            curNumS += num[i];

            if(idx == 0) {
                dfs(i + 1, expr + curNumS, curNum, curNum);
            } else {
                dfs(i + 1, expr + "+" + curNumS, sum + curNum, curNum);
                dfs(i + 1, expr + "-" + curNumS, sum - curNum, -curNum);
                dfs(i + 1, expr + "*" + curNumS, sum - prevNum + prevNum * curNum, prevNum * curNum);
            }
        }
    }
};