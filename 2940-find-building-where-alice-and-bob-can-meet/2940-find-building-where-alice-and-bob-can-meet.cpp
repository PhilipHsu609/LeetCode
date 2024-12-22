class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int hn = heights.size(), qn = queries.size();
        vector<vector<pair<int, int>>> q(hn);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(qn, -1);

        for(int i = 0; i < qn; i++) {
            int q1 = min(queries[i][0], queries[i][1]), q2 = max(queries[i][0], queries[i][1]);

            if(q1 == q2 || (q1 < q2 && heights[q1] < heights[q2])) {
                ans[i] = q2;
            } else {
                q[q2].push_back({max(heights[q1], heights[q2]), i});
            }
        }

        for(int i = 0; i < hn; i++) {
            while(!pq.empty() && pq.top().first < heights[i]) {
                ans[pq.top().second] = i;
                pq.pop();
            }
            for(auto &query : q[i]) {
                pq.push(query);
            }
        }

        return ans;
    }
};