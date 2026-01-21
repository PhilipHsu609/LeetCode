class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int cnt = 1;
        int mc = 1;
        int n = nums.size();
        for(int i = 1; i < n; ++i) {
            if(nums[i - 1] == nums[i]) {
                ++cnt;
            } else {
                cnt = 1;
            }
            mc = max(mc, cnt);
        }

        if(mc > n / 2) {
            return n - (n - mc) * 2;
        }
        return n % 2;
    }
};