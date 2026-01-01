class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;

        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; --i) {
            ret.push_back((digits[i] + carry) % 10);
            carry = (digits[i] + carry) / 10;
        }

        if(carry > 0) {
            ret.push_back(1);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};