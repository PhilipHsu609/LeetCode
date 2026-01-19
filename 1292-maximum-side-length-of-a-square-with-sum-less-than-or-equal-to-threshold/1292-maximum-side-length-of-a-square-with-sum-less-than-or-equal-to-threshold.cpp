class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1));

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                prefix[i][j] = prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        
        int ret = 0;
        int side = 1;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(i < side || j < side) {
                    continue;
                }
                int area = prefix[i][j] - prefix[i - side][j] - prefix[i][j - side] + prefix[i - side][j - side];
                if(area <= threshold) {
                    ret = side++;
                }
            }
        }

        return ret;
    }
};