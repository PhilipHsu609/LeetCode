class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<int> dir{1, 0, -1, 0, 1, -1, -1, 1, 1};

        if(grid[0][0] != 0) {
            return -1;
        }

        pq.push({1, 0, 0});
        dist[0][0] = 1;

        while(!pq.empty()) {
            auto [l, i, j] = pq.top();
            pq.pop();

            if(i == n - 1 && j == n - 1) {
                break;
            }

            if(l > dist[i][j]) {
                continue;
            }

            for(int d = 0; d < 8; ++d) {
                int ii = i + dir[d];
                int jj = j + dir[d + 1];

                if(ii < 0 || jj < 0 || ii == n || jj == n || grid[ii][jj] != 0 || l + 1 >= dist[ii][jj]) {
                    continue;
                }

                dist[ii][jj] = l + 1;
                pq.push({dist[ii][jj], ii, jj});
            }
        }

        return dist[n - 1][n - 1] == INT_MAX ? -1 : dist[n - 1][n - 1];
    }
};