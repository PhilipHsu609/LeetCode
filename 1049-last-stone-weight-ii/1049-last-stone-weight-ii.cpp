class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;

        for(int s : stones) {
            sum += s;
        }

        int target = sum / 2;
        vector<int> dp(target + 1);

        for(int s : stones) {
            for(int i = target; i >= s; --i) {
                dp[i] = max(dp[i], dp[i - s] + s);
            }
        }

        return sum - 2 * dp[target];
    }
};