class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<array<int, 3>> pq;
        vector<vector<int>> time(m, vector<int>(n, INT_MAX));
        vector<int> dir{0, 1, 0, -1, 0};

        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();

            if(time[i][j] <= t) {
                continue;
            }

            time[i][j] = t;

            for(int d = 0; d < 4; d++) {
                int ii = i + dir[d], jj = j + dir[d + 1];

                if(ii < 0 || jj < 0 || ii == m || jj == n) {
                    continue;
                }

                int t2 = max(t, grid[ii][jj]);
                if(time[ii][jj] > t2) {
                    pq.push({t2, ii, jj});
                }
            }
        }

        return time[m - 1][n - 1];
    }
};