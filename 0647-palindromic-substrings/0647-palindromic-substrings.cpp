class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, true));

        int ret = n;
        for(int d = 1; d < n; d++) {
            for(int i = 0; i < n - d; i++) {
                int j = i + d;
                if(s[i] == s[j] && (i == j + 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    ret++;
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return ret;
    }
};

/*
dp(i, j) = \begin{cases}
1 & i == j (single character) \\
s[i] == s[j] & i == j + 1 \\
s[i] == s[j] and dp[i + 1][j - 1] & i + 1 < j
\end{cases}
*/