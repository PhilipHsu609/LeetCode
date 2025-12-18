class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ret(n);
        stack<int> s;

        for(int i = n - 1; i >= 0; --i) {
            while(!s.empty() && prices[i] < s.top()) {
                s.pop();
            }

            if(s.empty()) {
                ret[i] = prices[i];
            } else {
                ret[i] = prices[i] - s.top();
            }

            s.push(prices[i]);
        }

        return ret;
    }
};