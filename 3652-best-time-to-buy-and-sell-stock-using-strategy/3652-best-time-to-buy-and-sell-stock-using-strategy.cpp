class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long profit = 0;
        long long ret = 0;

        for(int i = 0; i < n; ++i) {
            ret += prices[i] * strategy[i];
            if(k / 2 <= i && i < k) {
                profit += prices[i];
            } else if(i >= k) {
                profit += prices[i] * strategy[i];
            }
        }

        ret = max(ret, profit);
        for(int i = k; i < n; ++i) {
            // [0] 0 0  1  1 1
            //     0 0 [0] 1 1 [1]
            //                  i
            profit -= prices[i] * strategy[i];
            profit += prices[i];
            profit -= prices[i - k / 2];
            profit += prices[i - k] * strategy[i - k];

            ret = max(ret, profit);
        }

        return ret;
    }
};