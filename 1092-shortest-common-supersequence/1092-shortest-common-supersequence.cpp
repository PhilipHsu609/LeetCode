class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> prev(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    prev[i][j] = 0;
                } else {
                    if(dp[i - 1][j] >= dp[i][j - 1]) {
                        dp[i][j] = dp[i - 1][j];
                        prev[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i][j - 1];
                        prev[i][j] = 2;
                    }
                }
            }
        }

        string lcs;
        int i = m, j = n;
        while(i != 0 && j != 0) {
            if(prev[i][j] == 0) {
                lcs.push_back(str1[i - 1]);
                i--;
                j--;
            } else if(prev[i][j] == 1) {
                lcs.push_back(str1[i - 1]);
                i--;
            } else {
                lcs.push_back(str2[j - 1]);
                j--;
            }
        }

        while(i != 0) {
            lcs.push_back(str1[i - 1]);
            i--;
        }

        while(j != 0) {
            lcs.push_back(str2[j - 1]);
            j--;
        }

        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};