class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = 0;
        int nz = 0, no = 0;

        for(char ch : s) {
            if(ch == '0') {
                ++nz;
            }
        }

        int ret = nz;
        for(char ch : s) {
            if(ch == '0') {
                --nz;
            } else {
                ++no;
            }
            ret = min(ret, no + nz);
        }

        return ret;
    }
};