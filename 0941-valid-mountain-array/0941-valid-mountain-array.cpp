class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();

        if(n < 3) {
            return false;
        }

        int i = 1, j = n - 2;
        while(i < n) {
            if(arr[i - 1] >= arr[i]) {
                break;
            }
            ++i;
        }

        while(j >= 0) {
            if(arr[j] <= arr[j + 1]) {
                break;
            }
            --j;
        }

        return i - 1 == j + 1 && i - 1 >= 1 && j + 1 <= n - 2;
    }
};