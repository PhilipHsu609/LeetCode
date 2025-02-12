class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> m;
        int ret = -1;

        for(int n : nums) {
            int s = digitsum(n);
            if(m.find(s) != m.end()) {
                ret = max(ret, m[s] + n);
            }
            m[s] = max(m[s], n);
        }

        return ret;
    }

    int digitsum(int n) {
        int ret = 0;
        while(n > 0) {
            ret += n % 10;
            n /= 10;
        }
        return ret;
    }
};