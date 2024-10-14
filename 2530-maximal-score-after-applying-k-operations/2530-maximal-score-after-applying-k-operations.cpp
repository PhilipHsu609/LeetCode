class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long ret = 0;

        while(k-- > 0) {
            int val = pq.top();
            pq.pop();

            ret += val;
            pq.push(ceil(val / 3.0));
        }

        return ret;
    }
};