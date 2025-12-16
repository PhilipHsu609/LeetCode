class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;

        sort(intervals.begin(), intervals.end());

        for(const auto &itv : intervals) {
            if(ret.empty()) {
                ret.push_back(itv);
                continue;
            }

            if(ret.back()[1] >= itv[0]) {
                int start = min(ret.back()[0], itv[0]);
                int end = max(ret.back()[1], itv[1]);
                ret.back()[0] = start;
                ret.back()[1] = end;
            } else {
                ret.push_back(itv);
            }
        }

        return ret;
    }
};