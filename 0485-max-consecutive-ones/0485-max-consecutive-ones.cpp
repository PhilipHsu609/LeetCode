class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0;
        int cnt = 0;
        for(int n : nums) {
            if(n == 0) {
                cnt = 0;
            } else {
                ++cnt;
            }
            ret = max(ret, cnt);
        }
        return ret;
    }
};