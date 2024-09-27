class Solution {
public:
    void sortColors(vector<int> &nums) {
        int l = 0, m = 0, r = nums.size() - 1;

        while(m <= r) {
            if(nums[m] == 0) {
                swap(nums[l++], nums[m++]);
            } else if(nums[m] == 1) {
                m++;
            } else {
                swap(nums[m], nums[r--]);
            }
        }
    }

    void _sortColors(vector<int>& nums) {
        int colors[3]{};

        for(int n : nums)
            colors[n]++;

        int pos = 0, n = nums.size();
        for(int i = 0; i < 3; i++) {
            while(pos < n && colors[i]-- != 0) {
                nums[pos++] = i;
            }
        }
    }
};