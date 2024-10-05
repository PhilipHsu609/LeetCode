class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        return helper(arr, n - 1, 1, n, m);
    }

    int helper(const vector<int> &arr, int i, int start, int end, int m) {
        if(i < 0 || start > end || end - start + 1 < m) {
            return -1;
        }

        int n = arr.size();
        if(end - start + 1 == m) {
            return i + 1; 
        }

        if(start <= arr[i] && arr[i] <= end) {
            int l = helper(arr, i - 1, start, arr[i] - 1, m);
            int r = helper(arr, i - 1, arr[i] + 1, end, m);
            return max(l, r);
        }
        return helper(arr, i - 1, start, end, m);
    }
};