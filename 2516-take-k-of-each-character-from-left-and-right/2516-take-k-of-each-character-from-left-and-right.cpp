class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        unordered_map<char, int> count;

        for(char ch : s) {
            count[ch]++;
        }

        if(count['a'] < k || count['b'] < k || count['c'] < k) {
            return -1;
        }

        int ret = n;
        for(int start = 0, end = 0; end < n; end++) {
            count[s[end]]--;

            while(count['a'] < k || count['b'] < k || count['c'] < k) {
                count[s[start]]++;
                start++;
            }

            ret = min(ret, n - (end - start + 1));
        }

        return ret;
    }
};