class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq; // {cost, i, j}
        vector<vector<int>> dist(m, vector<int>(n, m + n));
        vector<int> dir{0, 1, 0, -1, 0, 1};


        pq.push({0, 0, 0});
        while(!pq.empty()) {
            auto [c, i, j] = pq.top();
            pq.pop();

            if(i == m - 1 && j == n - 1) {
                return c;
            }

            if(c > dist[i][j]) {
                continue;
            }

            dist[i][j] = c;
            for(int d = 0; d < 4; d++) {
                int ii = i + dir[d], jj = j + dir[d + 1];

                if(ii < 0 || jj < 0 || ii == m || jj == n) {
                    continue;
                }

                int w = getWeight(grid[i][j], i, j, ii, jj);
                if(dist[i][j] + w < dist[ii][jj]) {
                    dist[ii][jj] = dist[i][j] + w;
                    pq.push({dist[ii][jj], ii, jj});
                }
            }
        }

        return -1;
    }

    int getWeight(int dir, int i, int j, int ii, int jj) {
        switch(dir) {
            case 1:
                return i == ii && j + 1 == jj ? 0 : 1;
            case 2:
                return i == ii && j - 1 == jj ? 0 : 1;
            case 3:
                return i + 1 == ii && j == jj ? 0 : 1;
            case 4:
                return i - 1 == ii && j == jj ? 0 : 1;
            default:
                return -1;
        }
    }
};