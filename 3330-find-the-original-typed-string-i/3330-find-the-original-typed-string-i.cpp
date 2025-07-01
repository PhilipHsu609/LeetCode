class Solution {
public:
    int possibleStringCount(string word) {
        word += '*';

        int n = word.length();
        int ret = 1;

        char c = ' ';
        int cur = 1;
        for(int i = 0; i < n; i++) {
            if(c != word[i]) {
                c = word[i];
                ret += cur - 1;
                cur = 0;
            }
            cur++;
        }

        return ret;
    }
};