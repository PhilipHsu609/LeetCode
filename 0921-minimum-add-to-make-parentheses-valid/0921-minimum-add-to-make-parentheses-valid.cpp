class Solution {
public:
    int minAddToMakeValid(string s) {
        int stackSize = 0, missMatch = 0;

        for(char c : s) {
            if(c == '(') {
                stackSize++;
            } else if(stackSize > 0) {
                stackSize--;
            } else {
                missMatch++;
            }
        }

        return stackSize + missMatch;
    }
};