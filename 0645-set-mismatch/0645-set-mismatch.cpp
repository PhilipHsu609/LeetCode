class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int dup = -1;
        vector<bool> seen(n);

        for(int i = 0; i < n; ++i) {
            if(seen[nums[i] - 1]) {
                dup = nums[i];
            }
            seen[nums[i] - 1] = true;
            sum += i + 1;
            sum -= nums[i];
        }

        return {dup, sum + dup};
    }
};