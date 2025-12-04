class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int s = 0;
        int r = 0;

        for(char ch : directions) {
            if(ch == 'S') {
                s++;
            }
        }

        int i = 0;
        while(directions[i] == 'L') {
            r++, i++;
        }

        i = n - 1;
        while(directions[i] == 'R') {
            r++, i--;
        }

        return n - s - r;
    }
};