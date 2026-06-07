class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<int> idx(n);
        ranges::iota(idx, 0);
        ranges::sort(idx, [&](int a, int b) {
            return nums1[a] < nums1[b];
        });

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        vector<long long> ret(n);
        for(int i = 0; i < n; ++i) {
            ret[idx[i]] = sum;

            if(i > 0 && nums1[idx[i - 1]] == nums1[idx[i]]) {
                ret[idx[i]] = ret[idx[i - 1]];
            }

            sum += nums2[idx[i]];
            pq.push(nums2[idx[i]]);

            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
        }

        return ret;
    }
};

/*
[4, 2, 1, 5, 3]
[2, 1, 4, 0, 3]
*/