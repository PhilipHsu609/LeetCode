class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ret = k;
        for(int n : arr) {
            if(n <= ret) {
                ++ret;
            }
            if(n > ret) {
                return ret;
            }
        }
        return ret;
    }
};