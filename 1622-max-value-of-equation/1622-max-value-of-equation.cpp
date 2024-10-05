class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<int> dq;

        int ret = INT_MIN, n = points.size();
        for(int i = 0; i < n; i++) {
            while(!dq.empty() && points[i][0] - points[dq.front()][0] > k) {
                dq.pop_front();
            }
            if(!dq.empty()) {
                ret = max(ret, points[i][0] + points[i][1] + points[dq.front()][1] - points[dq.front()][0]);
            }
            while(!dq.empty() && points[dq.back()][1] - points[dq.back()][0] < points[i][1] - points[i][0]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return ret;
    }
};

/*
yi + yj + |xi - xj|

i < j
yi + yj + xj - xi -> max(yi - xi) + xj + yj
*/