class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int n = log2(label);

        vector<int> ret;
        while(n-- >= 0) {
            ret.push_back(label);
            label = pow(2, n + 1) - 1 - label / 2 + pow(2, n);
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};