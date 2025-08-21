class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int ret = 0;

        vector<int> hist(n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    hist[j] = 0;
                } else {
                    hist[j]++;
                }
            }

            stack<int> s;
            s.push(-1);

            int count = 0;
            for(int j = 0; j < n; j++) {
                while(s.top() != -1 && hist[s.top()] > hist[j]) {
                    int p1 = s.top(); s.pop();
                    int p2 = s.top();
                    count -= (p1 - p2) * (hist[p1] - hist[j]);
                }
                count += hist[j];
                ret += count;
                s.push(j);
            }
        }

        return ret;
    }
};