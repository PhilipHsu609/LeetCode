class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ret;
        for(int n : nums) {
            while(true) {
                int x = gcd(n, ret.empty() ? 1 : ret.back());

                if(x == 1) {
                    break;
                }

                n *= ret.back() / x;
                ret.pop_back();
            }

            ret.push_back(n);
        }

        return ret;
    }
};