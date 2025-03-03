class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int low = 0, mid = 0, high = 0;

        for(int n : nums) {
            if(n < pivot) {
                low++;
            } else if(n > pivot) {
                high++;
            } else {
                mid++;
            }
        }

        vector<int> ret(n);
        int i = 0, j = low, k = low + mid;
        for(int n : nums) {
            if(n < pivot) {
                ret[i++] = n;
            } else if(n > pivot) {
                ret[k++] = n;
            } else {
                ret[j++] = n;
            }
        }

        return ret;
    }
};