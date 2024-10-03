class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();

        stack<int> s;
        s.push(-1);

        int ret = 0;
        for(int i = 0; i < n; i++) {
            while(s.top() != -1 && heights[s.top()] > heights[i]) {
                int h = heights[s.top()]; s.pop();
                int w = i - 1 - s.top();
                ret = max(ret, w * h);
            }
            s.push(i);
        }

        heights.pop_back();

        return ret;
    }
};