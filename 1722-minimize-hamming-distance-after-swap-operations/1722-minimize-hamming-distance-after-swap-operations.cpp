struct DSU {
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
    vector<int> p;
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);

        for(const auto &s : allowedSwaps) {
            dsu.join(s[0], s[1]);
        }

        int ret = 0;
        unordered_map<int, vector<int>> comp;
        for(int i = 0; i < n; ++i) {
            comp[dsu.find(i)].push_back(i);
        }

        for(const auto &[k, v] : comp) {
            unordered_map<int, int> freq;
            for(int i : v) {
                ++freq[source[i]];
                --freq[target[i]];
            }
            int cnt = 0;
            for(auto [x, f] : freq) {
                cnt += abs(f);
            }
            ret += cnt / 2;
        }

        return ret;
    }
};