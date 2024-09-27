class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ret = target + 1e5;

        for(int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(abs(sum - target) < abs(target - ret)) {
                    ret = sum;
                }

                if(sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return ret;
    }
};