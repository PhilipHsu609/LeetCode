class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for(int i = 0; i < s.length(); i++) {
            int c = s[i] - 'a';
            if(first[c] == -1) {
                first[c] = i;
            }
            last[c] = i;
        }

        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(first[i] == -1)
                continue;

            unordered_set<char> between;
            for(int j = first[i] + 1; j < last[i]; j++) {
                between.insert(s[j]);
            }

            ans += between.size();
        }

        return ans;
    }
};