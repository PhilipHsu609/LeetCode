class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int ret = m * n - guards.size() - walls.size();

        vector<vector<int>> board(m, vector<int>(n));
        queue<array<int, 4>> q;

        for(const auto &g : guards) {
            board[g[0]][g[1]] = 1;
            q.push({g[0], g[1], 0, 1});
            q.push({g[0], g[1], 1, 0});
            q.push({g[0], g[1], -1, 0});
            q.push({g[0], g[1], 0, -1});
        }

        for(const auto &w : walls) {
            board[w[0]][w[1]] = 2;
        }

        while(!q.empty()) {
            auto [y, x, dy, dx] = q.front();
            q.pop();

            int xx = x + dx, yy = y + dy;
            if(xx < 0 || yy < 0 || xx == n || yy == m) {
                continue;
            }

            if(board[yy][xx] == 1 || board[yy][xx] == 2) {
                continue;
            }

            if(board[yy][xx] == 0) {
                --ret;
                board[yy][xx] = 3;
            }

            q.push({yy, xx, dy, dx});
        }

        return ret;
    }
};