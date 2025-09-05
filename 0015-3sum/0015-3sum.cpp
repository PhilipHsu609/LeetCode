class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;

        int n = nums.size();
        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    ret.push_back({nums[i], nums[j], nums[k]});
                }

                if(sum > 0) {
                    k--;
                    while(k > 0 && nums[k] == nums[k + 1]) {
                        k--;
                    }
                } else {
                    j++;
                    while(j < n - 1 && nums[j - 1] == nums[j]) {
                        j++;
                    }
                }
            }
        }

        return ret;
    }
};