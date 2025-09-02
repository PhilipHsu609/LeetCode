class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int> &p1, const vector<int> &p2) {
            // sort from right to left, bottom to top
            if(p1[0] == p2[0]) {
                return p1[1] < p2[1];
            }
            return p1[0] > p2[0];
        });

        int n = points.size();
        int ret = 0;
        for(int i = 0; i < n - 1; i++) { // bottom right candidate
            int y = INT_MAX; // running max of y coordinate
            int yi = points[i][1];
            for(int j = i + 1; j < n; j++) { // up left candidate
                int yj = points[j][1];
                if(yj >= yi && y > yj) {
                    ret++;
                    y = yj;
                }
            }
        }

        return ret;
    }
};