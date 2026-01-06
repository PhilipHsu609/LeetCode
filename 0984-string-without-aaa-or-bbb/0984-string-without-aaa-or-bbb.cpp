class Solution {
public:
    string strWithout3a3b(int a, int b) {
        char c[2] = {'a', 'b'};

        if(b > a) {
            swap(c[0], c[1]);
            swap(a, b);
        }

        string ret;
        while(a > 0 || b > 0) {
            if(a > b) {
                ret += c[0];
                --a;
            }
            if(a > 0) {
                ret += c[0];
                --a;
            }
            if(b > 0) {
                ret += c[1];
                --b;
            }
        }
        return ret;
    }
};