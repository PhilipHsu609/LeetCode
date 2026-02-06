class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;

        while(j < n) {
            if(1LL * nums[i] * k >= nums[j]) {
                ++j;
                continue;
            }
            ++i, ++j;
        }

        return n - (j - i);
    }
};

/*
max <= k * min

      v
x x x o o o o
*/