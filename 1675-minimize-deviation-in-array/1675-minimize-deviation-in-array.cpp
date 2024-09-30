class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq; // max heap

        int mini = INT_MAX;
        for(int n : nums) {
            int m = n % 2 == 1 ? 2 * n : n;
            pq.push(m);
            mini = min(mini, m);
        }

        int ret = INT_MAX;
        while(!pq.empty()) {
            int n = pq.top(); pq.pop();
            ret = min(ret, n - mini);

            if(n % 2 == 1) {
                break;
            }

            mini = min(mini, n / 2);
            pq.push(n / 2);
        }

        return ret;
    }
};