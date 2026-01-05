class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long ret = 0;
        int mini = INT_MAX;
        int neg = 0;

        for(auto &row : matrix) {
            for(auto ele : row) {
                if(ele < 0) {
                    ++neg;
                }
                ret += abs(ele);
                mini = min(mini, abs(ele));
            }
        }

        if(neg % 2 == 1) {
            ret -= 2 * mini;
        }

        return ret;
    }
};