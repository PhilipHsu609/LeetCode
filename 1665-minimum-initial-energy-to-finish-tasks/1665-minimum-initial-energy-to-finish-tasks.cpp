class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto &a, auto &b) {
            return a[0] - a[1] > b[0] - b[1];
        });

        int ret = 0;
        for(const auto &t : tasks) {
            ret = max(t[1], ret + t[0]);
        }

        return ret;
    }
};