class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        stack<int> s;
        int ret = 0;

        s.push(-1);
        for(int i = 0; i < n; ++i) {
            while(s.top() != -1 && heights[i] < heights[s.top()]) {
                int h = heights[s.top()]; s.pop();
                int w = i - s.top() - 1;
                ret = max(ret, h * w);
            }
            s.push(i);
        }

        return ret;
    }
};