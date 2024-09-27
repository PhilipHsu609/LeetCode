class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int n = customers.size();

        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) {
                sum += customers[i];
            }
        }

        int ret = 0;
        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 1) {
                sum += customers[i];
            }
            if(i >= minutes && grumpy[i - minutes] == 1) {
                sum -= customers[i - minutes];
            }
            ret = max(ret, sum);
        }

        return ret;
    }
};