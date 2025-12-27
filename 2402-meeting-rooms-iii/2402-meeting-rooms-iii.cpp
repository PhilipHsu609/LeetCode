class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> avail; // {room index}
        priority_queue<array<long, 2>, vector<array<long, 2>>, greater<array<long, 2>>> occupy; // {end time, room index}

        for(int i = 0; i < n; ++i) {
            avail.push(i);
        }

        sort(meetings.begin(), meetings.end());
        vector<int> freq(n);

        int m = meetings.size();
        for(int i = 0; i < m; ++i) {
            // free up occupied rooms
            while(!occupy.empty() && occupy.top()[0] <= meetings[i][0]) {
                auto [end, room] = occupy.top();
                occupy.pop();
                avail.push(room);
            }

            if(!avail.empty()) {
                auto room = avail.top();
                avail.pop();
                occupy.push({meetings[i][1], room});
                ++freq[room];
            } else {
                auto [end, room] = occupy.top();
                occupy.pop();

                occupy.push({end + (meetings[i][1] - meetings[i][0]), room});
                ++freq[room];
            }
        }

        int ret = -1;
        int f = 0;
        for(int i = 0; i < n; ++i) {
            if(freq[i] > f) {
                ret = i;
                f = freq[i];
            }
        }

        return ret;
    }
};