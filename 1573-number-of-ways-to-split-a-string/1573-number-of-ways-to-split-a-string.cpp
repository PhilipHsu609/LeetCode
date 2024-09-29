class Solution {
public:
    int numWays(string s) {
        int n = s.length(), MOD = 1e9 + 7;
        unordered_map<int, int> m; // nth 1 -> index

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                count++;
                m[count] = i;
            }
        }

        if(count == 0) {
            return static_cast<long long>(n - 1) * (n - 2) / 2 % MOD;
        }

        if(count % 3 != 0) {
            return 0;
        }

        // first cut \in [m[count / 3], m[count / 3 + 1])
        // last cut \in (m[2 * count / 3 - 1], m[2 * count / 3]]

        int ret = (static_cast<long long>(m[count / 3 + 1] - m[count / 3]) * (m[2 * count / 3 + 1] - m[2 * count / 3])) % MOD;

        return ret;
    }
};