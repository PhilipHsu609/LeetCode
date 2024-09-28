class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> prefix(m + 1, vector<int>(n + 1));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] + mat[i - 1][j - 1] - prefix[i - 1][j - 1];
            }
        }

        int l = 0, r = min(m, n);
        while(l < r) {
            int mid = l + (r - l + 1) / 2;

            bool ok = false;
            for(int i = mid; i <= m && !ok; i++) {
                for(int j = mid; j <= n; j++) {
                    int sum = prefix[i][j] - prefix[i - mid][j] - prefix[i][j - mid] + prefix[i - mid][j - mid];
                    if(sum <= threshold) {
                        ok = true;
                        break;
                    }
                }
            }

            if(ok) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
};