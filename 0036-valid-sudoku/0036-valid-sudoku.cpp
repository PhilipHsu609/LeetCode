class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        for (int i = 0; i < n; i++) {
            if (!test(board, i, row)) {
                return false;
            }
            if (!test(board, i, col)) {
                return false;
            }
            if (!test(board, i, block)) {
                return false;
            }
        }

        return true;
    }

    bool test(const vector<vector<char>>& b, int ith, auto func) {
        int n = b.size();
        unordered_set<char> s;
        for (int j = 0; j < n; j++) {
            char c = func(b, ith, j);
            if (c != '.' && s.count(c) != 0) {
                return false;
            }
            s.insert(c);
        }
        return true;
    }

    static char row(const vector<vector<char>>& b, int ith, int idx) {
        return b[ith][idx];
    }

    static char col(const vector<vector<char>>& b, int ith, int idx) {
        return b[idx][ith];
    }

    static char block(const vector<vector<char>>& b, int ith, int idx) {
        int n = b.size();
        int blk_row = ith / 3;
        int blk_col = ith % 3;
        int cell_row = idx / 3;
        int cell_col = idx % 3;
        return b[blk_row * 3 + cell_row][blk_col * 3 + cell_col];
    }
};