class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int l = 0, r = 1e7;

        while(l < r) {
            int mid = l + (r - l + 1) / 2;

            long long alloc = 0;
            for(int i = 0; i < n; i++) {
                if(candies[i] >= mid) {
                    alloc += candies[i] / mid;
                }
            }

            if(alloc >= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
};