class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> dp;

        for(int n : nums) {
            dp[n] += n;
        }

        int pick = 0, skip = 0;
        int last = INT_MIN;
        int ret = 0;

        for(const auto [k, v] : dp) {
            if(last + 1 == k) {
                // k - 1 exist
                // if we pick k, then we must skip k - 1
                int tmp = pick;
                pick = skip + v;
                skip = tmp;
            } else {
                skip = pick;
                pick += v;
            }
            last = k;
        }

        return max(pick, skip);
    }
};