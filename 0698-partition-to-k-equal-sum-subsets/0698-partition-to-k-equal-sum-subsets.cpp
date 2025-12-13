class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == 1) {
            return true;
        }
        if(k > n) {
            return false;
        }

        int sum = 0;
        for(int x : nums) {
            sum += x;
        }

        if(sum % k != 0) {
            return false;
        }

        int target = sum / k;
        vector<bool> used(n);
        sort(nums.rbegin(), nums.rend());

        return helper(nums, used, target, 0, k, 0);
    }

    bool helper(const vector<int> &nums, vector<bool> &used, int target, int sum, int k, int idx) {
        int n = used.size();

        if(sum == target) {
            if(k == 1) {
                return true;
            }
            return helper(nums, used, target, 0, k - 1, 0);
        }

        for(int i = idx; i < n; ++i) {
            if(used[i]) {
                continue;
            }

            if(sum + nums[i] > target) {
                continue;
            }

            sum += nums[i];
            used[i] = true;
            if(helper(nums, used, target, sum, k, i + 1)) {
                return true;
            }

            sum -= nums[i];
            used[i] = false;

            if(sum == 0 || sum + nums[i] == target) {
                break;
            }
        }

        return false;
    }
};