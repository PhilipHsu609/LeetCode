class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<array<int, 2>> es(n);

        for(int i = 0; i < n; i++) {
            es[i] = {efficiency[i], speed[i]};
        }

        sort(es.rbegin(), es.rend());

        priority_queue<int, vector<int>, greater<int>> pq;

        long long ret = 0, sum = 0;
        int MOD = 1e9 + 7;
        for(int i = 0; i < n; i++) {
            auto [e, s] = es[i];

            if(pq.size() == k) {
                sum -= pq.top();
                pq.pop();
            }

            pq.push(s);
            sum += s;
            ret = max(ret, sum * e);
        }

        return ret % MOD;
    }
};