class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ret = 0;
        int diag2 = 0;
        for(const auto &d : dimensions) {
            int l = d[0], w = d[1];

            if(l * l + w * w >= diag2) {
                if(l * l + w * w == diag2) {
                    ret = max(ret, l * w);
                } else {
                    ret = l * w;
                }
                diag2 = l * l + w * w;
            }
        }

        return ret;
    }
};