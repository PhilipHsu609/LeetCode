class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxi = 0, maxij = 0;
        long long ret = 0;
        for(int n : nums) {
            ret = max(ret, static_cast<long long>(maxij) * n);
            maxij = max(maxij, maxi - n);
            maxi = max(maxi, n);
        }
        return ret;
    }
};