class DSU {
public:
    DSU(int n) {
        p.resize(n);
        f.resize(n);
        iota(begin(p), end(p), 0);
    }

    int find(int x) {
        if(p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    void join(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if(px == py) {
            return;
        }

        p[py] = px;
    }

    vector<int> p;
    vector<int> f;
};

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ret = 0;

        DSU dsu(m * n);
        vector<int> f(m * n);

        auto idx = [n](int i, int j) {
            return i * n + j;
        };
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    continue;
                }

                f[idx(i, j)] = grid[i][j];

                if(i > 0 && grid[i - 1][j] != 0) {
                    f[idx(i, j)] += f[dsu.find(idx(i - 1, j))];
                    dsu.join(idx(i, j), idx(i - 1, j));
                }

                if(j > 0 && grid[i][j - 1] != 0 && dsu.find(idx(i, j)) != dsu.find(idx(i, j - 1))) {
                    f[idx(i, j)] += f[dsu.find(idx(i, j - 1))];
                    dsu.join(idx(i, j), idx(i, j - 1));
                }

                ret = max(ret, f[idx(i, j)]);
            }
        }

        return ret;
    }
};