class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> min_x(n + 1, n + 1), min_y(n + 1, n + 1), max_x(n + 1), max_y(n + 1);

        for(const auto &b : buildings) {
            min_x[b[1]] = min(min_x[b[1]], b[0]);
            max_x[b[1]] = max(max_x[b[1]], b[0]);
            min_y[b[0]] = min(min_y[b[0]], b[1]);
            max_y[b[0]] = max(max_y[b[0]], b[1]);
        }

        int ret = 0;
        for(const auto &b : buildings) {
            if(min_x[b[1]] < b[0] && b[0] < max_x[b[1]] && min_y[b[0]] < b[1] && b[1] < max_y[b[0]]) {
                ret++;
            }
        }

        return ret;
    }
};