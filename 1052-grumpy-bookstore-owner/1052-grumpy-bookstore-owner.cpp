class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int start = 0, cnt = 0, mcnt = 0, mstart = 0;
        for(int end = 0; end < n; end++) {
            if(grumpy[end] == 1) {
                cnt += customers[end];
            }

            if(end - start + 1 == minutes) {
                if(cnt > mcnt) {
                    mstart = start;
                    mcnt = cnt;
                }
                if(grumpy[start] == 1) {
                    cnt -= customers[start];
                }
                start++;
            }
        }

        int ret = 0;
        for(int i = 0; i < n; i++) {
            if(i >= mstart && i < mstart + minutes) {
                ret += customers[i];
            } else {
                if(grumpy[i] == 0) {
                    ret += customers[i];
                }
            }
        }

        return ret;
    }
};