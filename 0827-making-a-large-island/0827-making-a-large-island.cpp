class DSU {
public:
    DSU(int n) {
        p.resize(n);
        s.resize(n, 1);
        iota(begin(p), end(p), 0);
    }

    int find(int x) {
        if(x != p[x]) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    void join(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px != py) {
            p[py] = px;
            s[px] += s[py];
        }
    }
    vector<int> p, s;
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int ret = 0;
        DSU dsu(n * n);

        auto idx = [n](int i, int j) {
            return i * n + j;
        };

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 1) {
                    continue;
                }

                if(i > 0 && grid[i - 1][j] == 1) {
                    dsu.join(idx(i, j), idx(i - 1, j));
                }

                if(j > 0 && grid[i][j - 1] == 1 && dsu.find(idx(i, j)) != dsu.find(idx(i, j - 1))) {
                    dsu.join(idx(i, j), idx(i, j - 1));
                }

                ret = max(ret, dsu.s[dsu.find(idx(i, j))]);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0) {
                    continue;
                }

                unordered_set<int> ng;
                if(i > 0 && grid[i - 1][j] == 1) {
                    ng.insert(dsu.find(idx(i - 1, j)));
                }
                if(i < n - 1 && grid[i + 1][j] == 1) {
                    ng.insert(dsu.find(idx(i + 1, j)));
                }
                if(j > 0 && grid[i][j - 1] == 1) {
                    ng.insert(dsu.find(idx(i, j - 1)));
                }
                if(j < n - 1 && grid[i][j + 1] == 1) {
                    ng.insert(dsu.find(idx(i, j + 1)));
                }

                int ts = 1;
                for(int g : ng) {
                    ts += dsu.s[g];
                }

                ret = max(ret, ts);
            }
        }

        return ret;
    }
};