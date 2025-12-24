class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1);

        for(int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ret = n + 1;
        deque<int> dq;

        for(int i = 0; i <= n; ++i) {
            while(!dq.empty() && prefix[dq.back()] >= prefix[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            while(!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                ret = min(ret, i - dq.front());
                dq.pop_front();
            }
        }

        return ret == n + 1 ? -1 : ret;
    }
};