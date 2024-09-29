class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int sum = 0;

        for(int num : nums) {
            sum = (sum + num) % p;
        }

        if(sum == 0) {
            return 0;
        }

        int psum = 0, ret = n;
        unordered_map<int, int> m; // psum mod p -> index
        m[0] = -1;

        for(int i = 0; i < n; i++) {
            psum += nums[i];
            psum %= p;

            int x = (psum - sum + p) % p;
            if(m.find(x) != m.end()) {
                ret = min(ret, i - m[x]);
            }

            m[psum] = i;
        }

        return ret == n ? -1 : ret;
    }
};