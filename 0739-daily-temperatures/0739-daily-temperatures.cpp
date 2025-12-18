class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        vector<int> ret(n);

        for(int i = n - 1; i >= 0; --i) {
            while(!s.empty() && temperatures[i] >= temperatures[s.top()]) {
                s.pop();
            }
            if(s.empty()) {
                ret[i] = 0;
            } else {
                ret[i] = s.top() - i;
            }
            s.push(i);
        }

        return ret;
    }
};