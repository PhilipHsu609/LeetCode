class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        auto cmp = [](const array<int, 2> &a, const array<int, 2> &b) {
            double r1 = (a[1] * (a[0] + 1) - a[0] * (a[1] + 1)) / static_cast<double>(a[1] * (a[1] + 1));
            double r2 = (b[1] * (b[0] + 1) - b[0] * (b[1] + 1)) / static_cast<double>(b[1] * (b[1] + 1));
            return r1 < r2;
        };
        priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(cmp)> pq(cmp);

        double ratioSum = 0.0;
        for(const auto &c : classes) {
            double ratio = c[0] / static_cast<double>(c[1]);
            ratioSum += ratio;
            pq.push({c[0], c[1]});
        }

        for(int i = 1; i <= extraStudents; i++) {
            auto [nu, de] = pq.top();
            pq.pop();

            ratioSum -= nu / static_cast<double>(de);
            ratioSum += (nu + 1) / static_cast<double>(de + 1);

            pq.push({nu + 1, de + 1});
        }

        return ratioSum / n;
    }
};
/*
(n+1)/(d+1) - (n/d) = d(n+1)-n(d+1) / d(d+1)
*/