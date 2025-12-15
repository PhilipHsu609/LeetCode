class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ret = 1;
        int n = prices.size();
        int con_cnt = 1;

        for(int i = 1; i < n; ++i) {
            if(prices[i - 1] == prices[i] + 1) {
                ++con_cnt;
            } else {
                con_cnt = 1;
            }
            ret += con_cnt;
        }

        return ret;
    }
};