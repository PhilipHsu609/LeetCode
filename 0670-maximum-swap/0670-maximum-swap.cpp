class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);

        int maxIdx = -1;
        char maxDigit = 0;

        int l = -1, r = -1, n = s.size();
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] > maxDigit) {
                maxIdx = i;
                maxDigit = s[i];
                continue;
            }

            if(s[i] < maxDigit) {
                l = i;
                r = maxIdx;
            }
        }

        if(l == -1) {
            return num;
        }

        swap(s[l], s[r]);

        return stoi(s);
    }
};