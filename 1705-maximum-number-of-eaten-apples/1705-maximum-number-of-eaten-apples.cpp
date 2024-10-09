class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;

        int day = 0, n = apples.size();
        int ret = 0;
        while(day < n || !pq.empty()) {
            if(day < n) {
                pq.push({day + days[day], apples[day]});
            }

            while(!pq.empty() && pq.top()[0] <= day) {
                pq.pop();
            }

            if(!pq.empty()) {
                auto [rot, apple] = pq.top();
                pq.pop();
                if(apple > 1) {
                    pq.push({rot, apple - 1});
                }
                ret++;
            }

            day++;
        }

        return ret;
    }
};