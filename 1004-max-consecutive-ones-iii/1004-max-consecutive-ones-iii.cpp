class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int K = k;
        int ret = 0;

        for(int start = 0, end = 0; end < n; end++) {
            if(nums[end] == 0) {
                K--;
            }

            while(K < 0) {
                if(nums[start] == 0) {
                    K++;
                }
                start++;
            }
            
            ret = max(ret, end - start + 1);
        }

        return ret;
    }
};