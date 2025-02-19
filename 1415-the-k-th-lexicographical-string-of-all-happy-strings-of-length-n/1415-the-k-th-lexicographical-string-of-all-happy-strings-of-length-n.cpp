class Solution {
public:
    string getHappyString(int n, int k) {
        string ret, cur;
        dfs(n, k, cur, ret);
        return ret;
    }

    void dfs(int n, int &k, string &cur, string &ret) {
        if(n == 0) {
            k--;
            if(k == 0) {
                ret = cur;
            }
            return;
        }

        for(char c : {'a', 'b', 'c'}) {
            if(!cur.empty() && cur.back() == c) {
                continue;
            }
            cur.push_back(c);
            dfs(n - 1, k, cur, ret);
            cur.pop_back();
        }
    }
};