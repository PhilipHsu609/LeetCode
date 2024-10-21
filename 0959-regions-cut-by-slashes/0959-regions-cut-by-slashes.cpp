struct UF {
    UF(int n) : count{n} {
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
            count--;
        }
    }
    vector<int> p;
    int count;
};

class Solution {
public:
    int n;

    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        UF uf(n * n * 4);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                char ch = grid[i][j];

                if(i > 0) {
                    uf.join(g(i, j, 0), g(i - 1, j, 2));
                }
                if(j > 0) {
                    uf.join(g(i, j, 3), g(i, j - 1, 1));
                }

                if(ch != '/') {
                    uf.join(g(i, j, 0), g(i, j, 1));
                    uf.join(g(i, j, 2), g(i, j, 3));
                }
                if(ch != '\\') {
                    uf.join(g(i, j, 0), g(i, j, 3));
                    uf.join(g(i, j, 1), g(i, j, 2));
                }
            }
        }

        return uf.count;
    }

    int g(int i, int j, int k) {
        return (i * n + j) * 4 + k;
    }
};