class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        for(const auto &itv : intervals) {
            if(!pq.empty() && pq.top() < itv[0]) {
                pq.pop();
            }
            pq.push(itv[1]);
        }

        return pq.size();
    }
};