class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int lmax = INT_MIN, rmax = INT_MIN;

        int ret = 0;;

        while(l < r) {
            if(height[l] < height[r]) {
                if(height[l] > lmax) {
                    lmax = height[l];
                } else {
                    ret += lmax - height[l];
                }
                ++l;
            } else {
                if(height[r] > rmax) {
                    rmax = height[r];
                } else {
                    ret += rmax - height[r];
                }
                --r;
            }
        }

        return ret;
    }
};