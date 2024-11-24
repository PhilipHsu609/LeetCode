class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long ret = 0;
        int mini = INT_MAX;
        int neg = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                neg += static_cast<int>(matrix[i][j] < 0);
                mini = min(mini, abs(matrix[i][j]));
                ret += abs(matrix[i][j]);
            }
        }

        return neg % 2 == 0 ? ret : ret - 2 * mini;
    }
};