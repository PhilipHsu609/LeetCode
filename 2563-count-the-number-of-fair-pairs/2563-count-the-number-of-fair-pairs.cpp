class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums), end(nums));
        return countLower(nums, lower) - countLower(nums, upper + 1);
    }

    long long countLower(vector<int> &nums, int lower) {
        int n = nums.size();
        long long ret = 0;

        for(int i = 0, j = n - 1; i < j; j--) {
            while(i < j && nums[i] + nums[j] < lower) {
                i++;
            }
            ret += static_cast<long long>(j) - i;
        }

        return ret;
    }
};
