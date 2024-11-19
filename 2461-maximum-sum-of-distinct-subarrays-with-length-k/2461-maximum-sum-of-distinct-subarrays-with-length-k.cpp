class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size(), dup = 0;
        long long ret = 0, sum = 0;

        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
            sum += nums[i];

            if(freq[nums[i]] > 1) {
                dup++;
            }

            if(i >= k - 1) {
                if(dup == 0) {
                    ret = max(ret, sum);
                }

                freq[nums[i - k + 1]]--;
                sum -= nums[i - k + 1];

                if(freq[nums[i - k + 1]] > 0) {
                    dup--;
                }
            }
        }

        return ret;
    }
};