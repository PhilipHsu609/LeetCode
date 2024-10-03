class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> hist(n + 1, 0);

        int ret = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                hist[j] = matrix[i][j] == '0' ? 0 : hist[j] + 1;
            }

            stack<int> s;
            s.push(-1);
            for(int j = 0; j <= n; j++) {
                while(s.top() != -1 && hist[s.top()] > hist[j]) {
                    int h = hist[s.top()]; s.pop();
                    int w = j - 1 - s.top();
                    ret = max(ret, h * w);
                }
                s.push(j);
            }
        }

        return ret;
    }
};