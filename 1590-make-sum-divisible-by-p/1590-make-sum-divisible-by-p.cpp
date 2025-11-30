class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0LL) % p;

        if(target == 0) {
            return 0;
        }

        unordered_map<int, int> m;
        m[0] = -1;

        int ret = n;
        int cur = 0;
        for(int i = 0; i < n; i++) {
            cur = (cur + nums[i]) % p;

            int check = (cur - target + p) % p;
            if(m.find(check) != m.end()) {
                ret = min(ret, i - m[check]);
            }

            m[cur] = i;
        }

        return ret == n ? -1 : ret;
    }
};