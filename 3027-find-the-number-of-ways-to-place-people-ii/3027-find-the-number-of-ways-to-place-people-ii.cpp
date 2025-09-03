class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int> &p, const vector<int> &q) {
            if(p[0] == q[0]) {
                return p[1] > q[1];
            }
            return p[0] < q[0];
        });

        int n = points.size();
        int ret = 0;
        for(int i = 0; i < n - 1; i++) {
            int lastY = INT_MIN;
            for(int j = i + 1; j < n; j++) {
                if(points[i][1] >= points[j][1] && points[j][1] > lastY) {
                    ret++;
                    lastY = points[j][1];
                }
            }
        }

        return ret;
    }
};