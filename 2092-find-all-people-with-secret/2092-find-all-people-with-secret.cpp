class DSU {
public:
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool join(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) {
            return false;
        }
        parent[px] = py;
        return true;
    }

    void reset(int x) {
        parent[x] = x;
    }
private:
    vector<int> parent;
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](const auto &a, const auto &b) {
            return a[2] < b[2];
        });

        DSU dsu(n);
        dsu.join(0, firstPerson);

        vector<int> people;
        int time = -1;
        for(const auto &m : meetings) {
            int x = m[0], y = m[1];
            int t = m[2];

            if(time != t) {
                // remove people without secrets
                for(int p : people) {
                    if(dsu.find(0) != dsu.find(p)) {
                        dsu.reset(p);
                    }
                }
                people.clear();
                time = t;
            }

            people.push_back(x);
            people.push_back(y);
            dsu.join(x, y);
        }

        vector<int> ret;
        for(int i = 0; i < n; ++i) {
            if(dsu.find(0) == dsu.find(i)) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};