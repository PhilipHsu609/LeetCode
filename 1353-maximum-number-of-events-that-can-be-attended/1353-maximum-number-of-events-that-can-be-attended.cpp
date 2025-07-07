class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int ret = 0;

        priority_queue<int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end());

        for(int i = 0, d = 0; d <= 1e5; d++) {
            while(i < n && events[i][0] <= d) {
                pq.push(events[i][1]);
                i++;
            }

            while(!pq.empty() && pq.top() < d) {
                pq.pop();
            }

            if(!pq.empty()) {
                pq.pop();
                ret++;
            }
        }
        
        return ret;
    }
};