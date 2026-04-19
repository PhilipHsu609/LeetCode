class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> ret(n, vector<int>(m));
        queue<array<int, 3>> q;
        vector<int> dirs{0, 1, 0, -1, 0};

        for(const auto &src : sources) {
            q.push({src[0], src[1], src[2]});
        }

        while(!q.empty()) {
            unordered_map<int, int> cand;

            for(int s = q.size(); s > 0; --s) {
                auto [i, j, c] = q.front();
                q.pop();
                if(ret[i][j] == 0) {
                    cand[i * m + j] = max(cand[i * m + j], c);
                }
            }

            for(auto [k, v] : cand) {
                int i = k / m;
                int j = k % m;

                ret[i][j] = v;

                for(int d = 0; d < 4; ++d) {
                    int ii = i + dirs[d];
                    int jj = j + dirs[d + 1];

                    if(ii < 0 || ii == n || jj < 0 || jj == m || ret[ii][jj] != 0) {
                        continue;
                    }
                    
                    q.push({ii, jj, v});
                }
            }
        }

        return ret;
    }
};