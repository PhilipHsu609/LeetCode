class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n), outdeg(n);

        for(const auto &e : edges) {
            indeg[e[1]]++;
            outdeg[e[0]]++;
        }

        int root = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) {
                root = i;
                cnt++;
            }
        }

        return cnt == 1 ? root : -1;
    }
};