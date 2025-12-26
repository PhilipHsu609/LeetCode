class Solution {
public:
    int bestClosingTime(string customers) {
        int n = 0;
        int y = 0;

        for(char c : customers) {
            if(c == 'Y') {
                ++y;
            }
        }

        customers.push_back('N');

        int ret = customers.size();
        int p = ret;
        for(int i = 0; i < customers.size(); ++i) {
            if(y + n < p) {
                p = y + n;
                ret = i;
            }

            char c = customers[i];
            if(c == 'N') {
                ++n;
            } else {
                --y;
            }
        }

        return ret;
    }
};