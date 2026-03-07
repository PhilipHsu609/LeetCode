class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        vector<vector<int>> pre(n + 1, vector<int>(2)), suf(n + 1, vector<int>(2));

        for(int i = 1; i <= n; ++i) {
            if(i % 2 == 0) {
                pre[i][0] = pre[i - 1][0] + (s[i - 1] == '0');
                pre[i][1] = pre[i - 1][1] + (s[i - 1] == '1');
            } else {
                pre[i][0] = pre[i - 1][0] + (s[i - 1] == '1');
                pre[i][1] = pre[i - 1][1] + (s[i - 1] == '0');
            }
        }

        for(int i = n - 1; i >= 0; --i) {
            if(i % 2 == 0) {
                suf[i][0] = suf[i + 1][0] + (s[i] == '0');
                suf[i][1] = suf[i + 1][1] + (s[i] == '1');
            } else {
                suf[i][0] = suf[i + 1][0] + (s[i] == '1');
                suf[i][1] = suf[i + 1][1] + (s[i] == '0');
            }
        }

        int ret = min(pre[n][0], pre[n][1]);
        if(n % 2 == 0) {
            return ret;
        }
        
        for(int i = 0; i <= n; ++i) {
            ret = min(ret, pre[i][0] + suf[i][0]);
            ret = min(ret, pre[i][1] + suf[i][1]);
        }

        return ret;
    }
};

/*
[alt1][alt2] where alt1[-1] == alt2[0]

max prefix
max suffix
*/