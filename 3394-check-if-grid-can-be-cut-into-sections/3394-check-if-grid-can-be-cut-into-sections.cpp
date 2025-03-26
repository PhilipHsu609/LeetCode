class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<array<int, 2>> xaxis, yaxis;

        for(const auto &rec : rectangles) {
            xaxis.push_back({rec[0], rec[2]});
            yaxis.push_back({rec[1], rec[3]});
        }

        return canSplit(xaxis) || canSplit(yaxis);
    }

    bool canSplit(vector<array<int, 2>> &axis) {
        int split = 0;
        int cur = -1;
        sort(axis.begin(), axis.end());

        for(auto [start, end] : axis) {
            if(cur <= start) {
                split++;
                cur = end;
            } else if(start < cur && cur <= end) {
                cur = end;
            }
        }

        return split >= 3;
    }
};