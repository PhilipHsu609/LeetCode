class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> ret(n, vector<int>(m));
        queue<array<int, 3>> q;
        vector<int> dirs{0, 1, 0, -1, 0};

        sort(sources.begin(), sources.end(), [](const auto &a, const auto &b) {
            return a[2] > b[2];
        });

        for(const auto &src : sources) {
            ret[src[0]][src[1]] = src[2];
            q.push({src[0], src[1], src[2]});
        }

        while(!q.empty()) {
            auto [i, j, c] = q.front();
            q.pop();
            for(int d = 0; d < 4; ++d) {
                int ii = i + dirs[d];
                int jj = j + dirs[d + 1];
                if(ii < 0 || ii == n || jj < 0 || jj == m || ret[ii][jj] != 0) {
                    continue;
                }
                ret[ii][jj] = c;
                q.push({ii, jj, c});
            }
        }

        return ret;
    }
};