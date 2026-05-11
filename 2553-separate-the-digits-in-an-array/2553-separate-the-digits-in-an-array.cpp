class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ret;
        for(int n : nums) {
            int cnt = 0;
            while(n > 0) {
                ret.push_back(n % 10);
                n /= 10;
                ++cnt;
            }
            reverse(prev(ret.end(), cnt), ret.end());
        }
        return ret;
    }
};