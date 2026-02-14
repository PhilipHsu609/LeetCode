class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row(1, poured);
        for(int i = 1; i <= query_row; i++) {
            vector<double> next_row(i + 1, 0);
            for(int j = 0; j < i; j++) {
                if(row[j] > 1) {
                    next_row[j] += (row[j] - 1.0) / 2.0;
                    next_row[j + 1] += (row[j] - 1.0) / 2.0;
                }
            }
            row = next_row;
        }
        return min(1.0, row[query_glass]);
    }
};