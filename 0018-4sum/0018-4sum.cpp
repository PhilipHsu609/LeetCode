class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 0, prev = nums[0] - 1;
        while(i < n) {
            if(nums[i] != prev) {
                threeSum(nums, res, i, target - nums[i]);
                prev = nums[i];
            }
            i++;
        }    
        return res;
    }
    
    void threeSum(const vector<int> &nums, vector<vector<int>> &res, const int i, const int target) {
        int n = nums.size();
        int j = n - 1, prev = nums[0] - 1;
        while(j >= 2) {
            if(j != i && nums[j] != prev) {
                int l = i + 1, r = j - 1;
                while(l < r) {
                    int sum = nums[j] + nums[l] + nums[r];
                    if(sum == target) {
                        res.push_back({nums[i], nums[l], nums[r], nums[j]});
                        do{l++;}while(l < r && nums[l - 1] == nums[l]);
                        do{r--;}while(l < r && nums[r] == nums[r + 1]); 
                    } else if(sum < target) {
                        do{l++;}while(l < r && nums[l - 1] == nums[l]);
                    } else {
                        do{r--;}while(l < r && nums[r] == nums[r + 1]); 
                    }
                }
                prev = nums[j];
            }
            j--;
        }
    }
};