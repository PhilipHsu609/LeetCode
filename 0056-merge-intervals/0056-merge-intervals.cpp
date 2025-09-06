class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        vector<vector<int>> ret{intervals[0]};
        for(int i = 1; i < n; i++) {
            if(ret.back()[1] >= intervals[i][0]) {
                ret.back()[0] = min(ret.back()[0], intervals[i][0]);
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            } else {
                ret.push_back(intervals[i]);
            }
        }

        return ret;
    }
};