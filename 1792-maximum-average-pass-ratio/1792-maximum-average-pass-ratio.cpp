class Solution {
    using AD3 = array<double, 3>;
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<AD3> pq;

        int n = classes.size();
        for(const auto &c : classes) {
            double p = c[0], t = c[1];
            pq.push({(p + 1) / (t + 1) - p / t, p, t});
        }

        for(int i = 0; i < extraStudents; i++) {
            auto [dr, p, t] = pq.top();
            pq.pop();

            p += 1.0;
            t += 1.0;

            pq.push({(p + 1) / (t + 1) - p / t, p, t});
        }

        double avg = 0;
        while(!pq.empty()) {
            auto [dr, p, t] = pq.top();
            pq.pop();
            avg += p / t;
        }

        return avg / n;
    }
};