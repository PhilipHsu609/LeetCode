class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        unordered_map<char, int> cnt;

        for(char c : s) {
            cnt[c]++;
        }

        if(good(cnt, n / 4)) {
            return 0;
        }

        int ret = n;
        for(int start = 0, end = 0; end < n; end++) {
            cnt[s[end]]--;

            while(good(cnt, n / 4)) {
                ret = min(ret, end - start + 1);
                cnt[s[start]]++;
                start++;
            }
        }

        return ret;
    }

    bool good(unordered_map<char, int> &m, int target) {
        return m['Q'] <= target && m['W'] <= target && m['E'] <= target && m['R'] <= target;
    }
};