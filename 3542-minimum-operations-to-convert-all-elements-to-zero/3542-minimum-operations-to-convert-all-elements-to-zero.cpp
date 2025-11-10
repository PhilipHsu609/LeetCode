class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> s{0};
        int ret = 0;
        for(int n : nums) {
            while(!s.empty() && s.back() > n) {
                s.pop_back();
            }
            if(s.empty() || s.back() < n) {
                ret++;
                s.push_back(n);
            }
        }

        return ret;
    }
};