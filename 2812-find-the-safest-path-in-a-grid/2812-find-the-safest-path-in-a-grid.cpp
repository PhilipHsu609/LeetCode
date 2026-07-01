class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<int> dirs{0, 1, 0, -1, 0};

        queue<array<int, 2>> q;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for(int d = 0; d < 4; ++d) {
                int ii = i + dirs[d];
                int jj = j + dirs[d + 1];

                if(ii < 0 || jj < 0 || ii == r || jj == c || grid[ii][jj] != 0) {
                    continue;
                }

                grid[ii][jj] = grid[i][j] + 1;
                q.push({ii, jj});
            }
        }

        priority_queue<array<int, 3>> pq;
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()) {
            auto [s, i, j] = pq.top();
            pq.pop();

            if(i == r - 1 && j == c - 1) {
                return s - 1;
            }

            for(int d = 0; d < 4; ++d) {
                int ii = i + dirs[d];
                int jj = j + dirs[d + 1];

                if(ii < 0 || jj < 0 || ii == r || jj == c || grid[ii][jj] == -1) {
                    continue;
                }

                pq.push({min(grid[ii][jj], s), ii, jj});
                grid[ii][jj] = -1;
            }
        }

        return -1;
    }
};