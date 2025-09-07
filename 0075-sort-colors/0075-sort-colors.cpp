class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int r = 0, w = 0, b = n - 1;

/*
    r: the available position for red (nums[0:r] are red)
    w: unclassified (nums[r:w] are white)
    b: the available position for blue (nums[w:] are blue)
*/

        while(w <= b) {
            if(nums[w] == 0) {
                swap(nums[r], nums[w]);
                r++, w++; // we swap an element into nums[0:r], so both r and w must increase
            } else if(nums[w] == 1) {
                w++;
            } else {
                swap(nums[w], nums[b]);
                b--;
            }
        }
    }
};