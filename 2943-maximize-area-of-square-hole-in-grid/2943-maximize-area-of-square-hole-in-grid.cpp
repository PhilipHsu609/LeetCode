class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hcnt = 1;
        int maxh = 1;
        for(int i = 1; i < hBars.size(); ++i) {
            if(hBars[i - 1] + 1 == hBars[i]) {
                ++hcnt;
            } else {
                hcnt = 1;
            }
            maxh = max(maxh, hcnt);
        }

        int vcnt = 1;
        int maxv = 1;
        for(int i = 1; i < vBars.size(); ++i) {
            if(vBars[i - 1] + 1 == vBars[i]) {
                ++vcnt;
            } else {
                vcnt = 1;
            }
            maxv = max(maxv, vcnt);
        }

        int side = min(maxh + 1, maxv + 1);
        return side * side;
    }
};