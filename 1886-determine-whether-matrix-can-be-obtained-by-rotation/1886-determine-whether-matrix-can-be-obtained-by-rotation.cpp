class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < 4; ++i) {
            if(equal(mat, target)) {
                return true;
            }
            rotate90(mat);
        }
        return false;
    }

    void rotate90(vector<vector<int>> &mat) {
        int n = mat.size();
        // transpose
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        // swap rows
        for(int i = 0; i < n / 2; ++i) {
            swap(mat[i], mat[n - i - 1]);
        }
    }

    bool equal(const vector<vector<int>> &a, const vector<vector<int>> &b) {
        int n = a.size();
        for(int i = 0; i < n; ++i) {
            if(a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
};

/*
0 0 -> 1 0
1 0    0 0

1 0
0 0
*/