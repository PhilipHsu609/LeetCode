class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int psum = 0, ret = 0;
        unordered_map<int, int> m; // psum mod k -> count;
        m[0] = 1;

        for(int n : nums) {
            psum += n;
            psum = ((psum % k) + k) % k;

            if(m.find(psum) != m.end()) {
                ret += m[psum];
            }

            m[psum]++;
        }

        return ret;
    }
};