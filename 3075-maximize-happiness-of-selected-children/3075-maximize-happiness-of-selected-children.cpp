class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());

        long long ret = 0;
        for(int i = 0; i < k; ++i) {
            ret += happiness[i] - i;
        }
        return ret;
    }
};