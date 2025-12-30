class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int ret = 0;
        int last = INT_MIN;
        for(int i = 0; i < nums.size(); ++i) {
            int up = nums[i] + k;
            int lo = nums[i] - k;

            if(last < lo) {
                last = lo;
                ++ret;
            } else if(last < up) {
                ++last;
                ++ret;
            }
        }

        return ret;
    }
};