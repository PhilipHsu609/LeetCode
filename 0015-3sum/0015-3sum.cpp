class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            int l = i + 1, r = n - 1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if(sum == 0) {
                    ret.push_back({nums[i], nums[l], nums[r]});
                }

                if(sum > 0) {
                    r--;
                    while(r > 0 && nums[r] == nums[r + 1]) {
                        r--;
                    }
                } else {
                    l++;
                    while(l < n && nums[l - 1] == nums[l]) {
                        l++;
                    }
                }
            } 
        }

        return ret;
    }
};