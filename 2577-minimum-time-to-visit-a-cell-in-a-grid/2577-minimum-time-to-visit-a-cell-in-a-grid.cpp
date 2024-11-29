class Solution {
public:
    using int3 = array<int, 3>;

    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if(grid[1][0] > 1 && grid[0][1] > 1) {
            return -1;
        }

        vector<int> dirs{0, 1, 0, -1, 0};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<int3, vector<int3>, greater<int3>> pq;

        pq.push({grid[0][0], 0, 0}); // {time, i, j}

        while(!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();

            if(i == m - 1 && j == n - 1) {
                return t;
            }

            if(visited[i][j]) {
                continue;
            }

            visited[i][j] = true;
            for(int d = 0; d < 4; d++) {
                int ii = i + dirs[d], jj = j + dirs[d + 1];

                if(ii < 0 || jj < 0 || ii == m || jj == n || visited[ii][jj]) {
                    continue;
                }

                int nt = max(t + 1, grid[ii][jj] + (((grid[ii][jj] - t) % 2 == 0) ? 1 : 0));
                pq.push({nt, ii, jj});
            }
        }

        return -1;
    }
};