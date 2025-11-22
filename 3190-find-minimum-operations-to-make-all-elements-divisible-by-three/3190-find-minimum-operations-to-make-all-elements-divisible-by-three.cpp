class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ret = 0;
        for(int n : nums) {
            int r = n % 3;
            ret += min(r, 3 - r);
        }
        return ret;
    }
};