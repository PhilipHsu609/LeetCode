class Solution {
public:
    vector<vector<int>> moves{{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

    int slidingPuzzle(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        int zero = -1;
        string s;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 0) {
                    zero = i * n + j;
                }
                s += board[i][j] + '0';
            }
        }

        unordered_map<string, int> seen;
        queue<pair<string, int>> q;

        seen[s] = 0;
        q.push({s, zero});

        while(!q.empty()) {
            s = q.front().first;
            zero = q.front().second;
            q.pop();

            if(s == "123450") {
                return seen[s];
            }

            for(int nzero : moves[zero]) {
                string ns(s);
                swap(ns[zero], ns[nzero]);

                if(seen.find(ns) == seen.end()) {
                    seen[ns] = seen[s] + 1;
                    q.push({ns, nzero});
                }
            }
        }

        return -1;
    }
};