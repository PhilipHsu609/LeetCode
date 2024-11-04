class Solution {
public:
    string compressedString(string word) {
        string comp;
        int n = word.length();

        char c = ' ';
        int i = 0;
        int count = 0;

        while(i < n) {
            c = word[i];
            while(i < n && count < 9 && word[i] == c) {
                count++;
                i++;
            }
            comp += to_string(count) + c;
            count = 0;
        }

        return comp;
    }
};