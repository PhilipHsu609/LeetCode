struct DSU {
    vector<int> p;

    DSU(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
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
        if(px != py) {
            p[px] = py;
        }
    }
};
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        DSU dsu(m * n);

        auto idx = [n](int i, int j) {
            return i * n + j;
        };

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i > 0 && grid[i][j] == grid[i - 1][j]) {
                    if(dsu.find(idx(i, j)) == dsu.find(idx(i - 1, j))) {
                        return true;
                    }
                    dsu.join(idx(i, j), idx(i - 1, j));
                }
                if(j > 0 && grid[i][j] == grid[i][j - 1]) {
                    if(dsu.find(idx(i, j)) == dsu.find(idx(i, j - 1))) {
                        return true;
                    }
                    dsu.join(idx(i, j), idx(i, j - 1));
                }
            }
        }

        return false;
    }
};