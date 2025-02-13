class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());

        int op = 0;
        while(pq.size() >= 2 && pq.top() < k) {
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            pq.push(min(x, y) * 2LL + max(x, y));
            op++;
        }

        return op;
    }
};