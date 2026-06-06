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

    bool join(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) {
            return false;
        }

        p[px] = py;
        return true;
    }
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        int comp = n;
        int ret = 0;

        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        for(const auto &e : edges) {
            if(comp <= k) {
                break;
            }

            if(dsu.find(e[0]) != dsu.find(e[1])) {
                dsu.join(e[0], e[1]);
                --comp;
            }

            ret = e[2];
        }

        return ret;
    }
};