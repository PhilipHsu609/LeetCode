class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> a(n), b(n);

        a[0] = static_cast<int>(s[0] == 'a');
        b[n - 1] = static_cast<int>(s[n - 1] == 'b');
        for(int i = 1; i < n; ++i) {
            a[i] = a[i - 1] + static_cast<int>(s[i] == 'a');
            b[n - 1 - i] = b[n - i] + static_cast<int>(s[n - 1 - i] == 'b');
        }

        int ret = n;
        for(int i = 0; i < n; ++i) {
            ret = min(ret, n - a[i] - b[i]);
        }

        return ret;
    }
};