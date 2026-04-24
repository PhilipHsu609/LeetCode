class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0, r = 0, d = 0;
        for(char c : moves) {
            if(c == 'L')
                l++;
            if(c == 'R')
                r++;
            if(c == '_')
                d++;
        }
        return abs(l - r) + d;
    }
};