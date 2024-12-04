class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        int i = 0, j = 0;
        
        while(i != m && j != n) {
            int diff = (str2[j] - 'a') - (str1[i] - 'a');
            if(diff == 0 || diff == 1 || diff == -25)
                i++, j++;
            else
                i++;
        }
        
        return j == n;
    }
};