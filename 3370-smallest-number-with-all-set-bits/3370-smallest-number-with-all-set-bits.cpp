class Solution {
public:
    int smallestNumber(int n) {
        int i = 0;
        while((1 << i) - 1 < n) {
            i++;
        }
        return (1 << i) - 1;
    }
};