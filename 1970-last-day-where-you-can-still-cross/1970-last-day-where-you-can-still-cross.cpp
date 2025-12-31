class DSU {
public:
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

    bool join(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) {
            return false;
        }

        p[px] = py;
        return true;
    }
private:
    vector<int> p;
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;

        DSU dsu(n + 2); // n for virtual top and n + 1 for virtual bottom
        unordered_set<int> lands;
        vector<int> dir{0, 1, 0, -1, 0};

        for(int i = cells.size() - 1; i >= 0; --i) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            int idx = r * col + c;

            if(r == 0) {
                dsu.join(idx, n);
            }
            if(r == row - 1) {
                dsu.join(idx, n + 1);
            }

            for(int d = 0; d < 4; ++d) {
                int nr = r + dir[d];
                int nc = c + dir[d + 1];
                int nidx = nr * col + nc;

                if(nr < 0 || nc < 0 || nr == row || nc == col || lands.count(nidx) == 0) {
                    continue;
                }

                dsu.join(idx, nidx);
            }

            if(dsu.find(n) == dsu.find(n + 1)) {
                return i;
            }

            lands.insert(idx);
        }

        return -1;
    }
};