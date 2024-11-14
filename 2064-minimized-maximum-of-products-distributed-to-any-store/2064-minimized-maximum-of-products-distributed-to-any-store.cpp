class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = *max_element(begin(quantities), end(quantities));
        while(l < r) {
            int mid = l + (r - l) / 2;

            if(canDistribute(quantities, mid, n)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

    bool canDistribute(const vector<int> &q, int k, int n) {
        int m = q.size();
        for(int i = 0; i < m; i++) {
            if(q[i] <= k) {
                n--;
            } else {
                n -= (q[i] + k - 1) / k;
            }
        }
        return n >= 0;
    }
};