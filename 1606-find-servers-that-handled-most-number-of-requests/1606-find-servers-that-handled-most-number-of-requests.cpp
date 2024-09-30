class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int> count(k, 0);

        // available servers
        set<int> free;
        for(int i = 0; i < k; i++) {
            free.insert(i);
        }

        // servers that are currently working
        // {end time, server id}
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> busy;

        for(int i = 0; i < n; i++) {
            // we remove the servers that have already done
            while(!busy.empty() && busy.top()[0] <= arrival[i]) {
                free.insert(busy.top()[1]);
                busy.pop();
            }

            // find an available server to handle the ith request
            if(free.empty()) {
                continue;
            }

            auto it = free.lower_bound(i % k);
            if(it == free.end()) {
                it = free.begin();
            }

            count[*it]++;
            busy.push({arrival[i] + load[i], *it});
            free.erase(it);
        }

        vector<int> ret;
        int maxcount = *max_element(count.begin(), count.end());
        for(int i = 0; i < k; i++) {
            if(count[i] == maxcount) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};