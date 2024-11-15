class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        int r = n - 1;
        while(r > 0 && arr[r - 1] <= arr[r]) {
            r--;
        }

        if(r == 0) {
            return 0;
        }

        int ret = r;
        for(int l = 0; l < n; l++) {
            if(l > 0 && arr[l - 1] > arr[l]) {
                break;
            }
            while(r < n && arr[l] > arr[r]) {
                r++;
            }
            ret = min(ret, r - l - 1);
        }

        return ret;
    }
};