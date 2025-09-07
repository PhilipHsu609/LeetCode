class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int s = 1;
        int cand = nums[0];       

        for(int i = 1; i < n; i++) {
            if(s == 0) {
                s++;
                cand = nums[i];
            } else if(nums[i] == cand) {
                s++;
            } else {
                s--;
            }
        }

        return cand;
    }
};