class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ret(prices);

        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && prices[s.top()] >= prices[i]) {
                ret[s.top()] = prices[s.top()] - prices[i];
                s.pop();
            }
            s.push(i);
        }

        return ret;
    }
};