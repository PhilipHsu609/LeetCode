class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), q = queries.size();
        vector<array<int, 2>> q2;

        for(int i = 0; i < q; i++) {
            q2.push_back({queries[i], i});
        }

        sort(begin(items), end(items));
        sort(begin(q2), end(q2));

        vector<int> ret(q);
        int j = 0; // item
        int maxB = 0;

        for(int i = 0; i < q; i++) {
            while(j < n && items[j][0] <= q2[i][0]) {
                maxB = max(maxB, items[j][1]);
                j++;
            }

            ret[q2[i][1]] = maxB;
        }

        return ret;
    }
};