class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ret;
        int r = 0;
        for(int n : nums) {
            r = (r * 2) % 5;
            r = (r + n) % 5;
            ret.push_back(r == 0);
        }
        return ret;
    }
};