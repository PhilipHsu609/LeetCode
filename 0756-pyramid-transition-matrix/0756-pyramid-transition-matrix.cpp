class Solution {
public:
    bool allowMap[6][6][6] = {};
    set<vector<int>> visited;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(const auto &allow : allowed) {
            allowMap[allow[0] - 'A'][allow[1] - 'A'][allow[2] - 'A'] = true;
        }

        int n = bottom.size();
        vector<int> cur_row(n), next_row(n - 1);

        for(int i = 0; i < n; ++i) {
            cur_row[i] = bottom[i] - 'A';
        }

        return helper(n, 0, cur_row, next_row);
    }

    bool helper(int layer, int col, const vector<int> &cur_row, vector<int> &next_row) {
        if(layer == 1) {
            return true;
        }

        if(col == next_row.size()) {
            if(visited.count(next_row) == 0) {
                vector<int> new_row(next_row.size() - 1);
                visited.insert(next_row);
                return helper(layer - 1, 0, next_row, new_row);
            }
            return false;
        }

        bool ret = false;
        int backup = next_row[col];
        for(int c = 0; c < 6; ++c) {
            if(allowMap[cur_row[col]][cur_row[col + 1]][c]) {
                next_row[col] = c;
                ret |= helper(layer, col + 1, cur_row, next_row);
                if(ret) {
                    break;
                }
            }
        }
        next_row[col] = backup;

        return ret;
    }
};