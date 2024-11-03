class Solution {
public:
    vector<int> dirs{0, 1, 0, -1, 0};

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> pq;

        dist[0][0] = 0;
        pq.push({0, 1, 0, 0});

        while(!pq.empty()) {
            auto [time, step, i, j] = pq.top(); pq.pop();

            if(i == n - 1 && j == m - 1) {
                return time;
            }

            for(int d = 0; d < 4; d++) {
                int ii = i + dirs[d], jj = j + dirs[d + 1];

                if(ii < 0 || jj < 0 || ii == n || jj == m) {
                    continue;
                }

                int ntime = max(moveTime[ii][jj], time) + step;
                int nstep = step == 1 ? 2 : 1;

                if(ntime < dist[ii][jj]) {
                    dist[ii][jj] = ntime;
                    pq.push({ntime, nstep, ii, jj});
                }
            }
        }

        return -1;
    }
};