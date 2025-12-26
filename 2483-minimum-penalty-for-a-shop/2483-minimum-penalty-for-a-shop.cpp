class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int penalty = 0;
        int min_penalty = 0;
        int ret = 0;

        for(int i = 0; i < n; ++i) {
            if(customers[i] == 'N') {
                ++penalty;
            } else {
                --penalty;
            }

            if(penalty < min_penalty) {
                min_penalty = penalty;
                ret = i + 1;
            }
        }

        return ret;
    }
};