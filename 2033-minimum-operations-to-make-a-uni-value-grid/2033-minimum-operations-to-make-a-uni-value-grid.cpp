class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        for(const auto &row : grid) {
            for(int n : row) {
                nums.push_back(n);
            }
        }

        sort(nums.begin(), nums.end());

        int target = nums[nums.size() / 2];
        int r = target % x;
        
        int ret = 0;
        for(int n : nums) {
            if(n % x != r) {
                return -1;
            }
            ret += abs(target - n) / x;
        }

        return ret;
    }
};