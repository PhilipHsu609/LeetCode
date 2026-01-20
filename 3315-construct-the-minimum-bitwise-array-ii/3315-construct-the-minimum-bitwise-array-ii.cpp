class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ret;
        for(int n : nums) {
            if(n == 2) {
                ret.push_back(-1);
            } else {
                int m = n + 1;
                m = (m & (-m)) / 2;
                ret.push_back(n - m);
            }
        }
        return ret;
    }
};