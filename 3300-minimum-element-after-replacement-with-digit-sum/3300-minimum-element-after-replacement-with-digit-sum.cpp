class Solution {
public:
    int minElement(vector<int>& nums) {
        int ret = INT_MAX;
        for(int n : nums) {
            ret = min(ret, ds(n));
        }
        return ret;
    }

    int ds(int x) {
        int ret = 0;
        while(x > 0) {
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }
};