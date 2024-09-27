class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ret = 0;

        while(l < r) {
            ret = max(ret, (r - l) * min(height[l], height[r]));

            if(height[l] <= height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return ret;
    }
};