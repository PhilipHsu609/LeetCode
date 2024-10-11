class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq; // {leave time, seat number}

        int targetArrival = times[targetFriend][0];

        sort(times.begin(), times.end());

        set<int> freeSeats;
        int seat = 0;
        for(const auto &t : times) {
            int at = t[0];
            int lt = t[1];

            while(!pq.empty() && pq.top()[0] <= at) {
                freeSeats.insert(pq.top()[1]);
                pq.pop();
            }

            int curSeat = 0;
            if(freeSeats.empty()) {
                curSeat = seat++;
            } else {
                curSeat = *freeSeats.begin();
                freeSeats.erase(freeSeats.begin());
            }

            pq.push({lt, curSeat});

            if(at == targetArrival) {
                return curSeat;
            }
        }

        return 0;
    }
};