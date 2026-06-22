class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26);
        for(char ch : text) {
            ++freq[ch - 'a'];
        }

        int ret = INT_MAX;
        for(char ch : {'b', 'a', 'n'}) {
            ret = min(ret, freq[ch - 'a']);
        }
        for(char ch : {'l', 'o'}) {
            ret = min(ret, freq[ch - 'a'] / 2);
        }

        return ret;
    }
};