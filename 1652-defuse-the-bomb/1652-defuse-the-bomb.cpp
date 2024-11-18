class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ret(n);

        if(k > 0) {
            int sum = 0;
            for(int i = 1; i <= k; i++) {
                sum += code[i];
            }
            for(int i = 0; i < n; i++) {
                ret[i] = sum;
                sum -= code[(i + 1) % n];
                sum += code[(i + k + 1) % n];
            }
        }

        if(k < 0) {
            k = -k;
            int sum = 0;
            for(int i = n - 1; i >= n - k; i--) {
                sum += code[i];
            }
            for(int i = 0; i < n; i++) {
                ret[i] = sum;
                sum += code[i];
                sum -= code[(i - k + n) % n];
            }
        }

        return ret;
    }
};