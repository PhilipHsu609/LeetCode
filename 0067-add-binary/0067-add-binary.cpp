class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length()) {
            swap(a, b);
        }

        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while(i >= 0 || j >= 0) {
            int nxt = carry;
            if(i >= 0) {
                nxt += a[i] - '0';
            }
            if(j >= 0) {
                nxt += b[j] - '0';
                --j;
            }
            carry = nxt / 2;
            a[i] = (nxt % 2) + '0';
            --i;
        }

        if(carry == 1 && i < 0) {
            return "1" + a;
        }
        return a;
    }
};