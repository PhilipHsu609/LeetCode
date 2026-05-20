class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> freq(n);
        vector<int> ret(n);

        for(int i = 0; i < n; i++) {
            if(i > 0) {
                ret[i] = ret[i - 1];
            }

            freq[A[i] - 1]++;
            if(freq[A[i] - 1] == 2) {
                ret[i]++;
            }

            freq[B[i] - 1]++;
            if(freq[B[i] - 1] == 2) {
                ret[i]++;
            }
        }

        return ret;
    }
};