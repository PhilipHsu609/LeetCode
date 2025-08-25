class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ret;

        for(int dia = 1; dia <= m + n - 1; dia++) {
            if(dia % 2 == 1) {
                // right-up
                int starty = min(dia - 1, m - 1);
                int startx = dia - starty - 1;
                while(starty >= 0 && startx < n) {
                    ret.push_back(mat[starty][startx]);
                    starty -= 1;
                    startx += 1;
                }
            } else {
                // left-down
                int startx = min(dia - 1, n - 1);
                int starty = dia - startx - 1;
                while(starty < m && startx >= 0) {
                    ret.push_back(mat[starty][startx]);
                    starty += 1;
                    startx -= 1;
                }
            }
        }

        return ret;
    }
};