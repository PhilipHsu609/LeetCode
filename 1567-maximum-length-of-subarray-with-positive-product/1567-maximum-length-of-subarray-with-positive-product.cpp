class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0, neg = 0;
        int ret = 0;

        for(int n : nums) {
            if (n == 0) {
                pos = 0;
                neg = 0;
            } else if (n > 0) {
                ++pos;
                neg += static_cast<int>(neg > 0);
            } else {
                int tmp = pos;
                pos = (neg == 0) ? 0 : neg + 1;
                neg = tmp + 1;
            }
            ret = max(ret, pos);
        }

        return ret;
    }
};