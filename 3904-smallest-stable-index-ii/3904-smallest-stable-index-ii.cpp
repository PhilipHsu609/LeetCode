class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n + 1, INT_MIN), mini(n + 1, INT_MAX);

        for(int i = 0; i < n; ++i) {
            maxi[i + 1] = max(maxi[i], nums[i]);
            mini[n - i - 1] = min(mini[n - i], nums[n - i - 1]);
        }
        
        for(int i = 0; i < n; ++i) {
            if(maxi[i + 1] - mini[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};