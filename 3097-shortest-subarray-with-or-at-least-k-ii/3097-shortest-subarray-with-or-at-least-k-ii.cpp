class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bits(32);
        int n = nums.size();
        int ret = n + 1;
        int win_or = 0;

        for(int start = 0, end = 0; end < n; end++) {
            win_or = add_win(bits, win_or, nums[end]);

            while(start <= end && win_or >= k) {
                ret = min(ret, end - start + 1);
                win_or = remove_win(bits, win_or, nums[start]);
                start++;
            }
        }

        return ret == n + 1 ? -1 : ret;
    }

    int add_win(vector<int> &bits, int val, int num) {
        for(int i = 0; i < 32; i++) {
            bits[i] += (num & (1 << i)) != 0 ? 1 : 0;
        }
        return val | num;
    }

    int remove_win(vector<int> &bits, int val, int num) {
        for(int i = 0; i < 32; i++) {
            bits[i] -= (num & (1 << i)) != 0 ? 1 : 0;

            if(bits[i] == 0) {
                val = val & ~(1 << i);
            }
        }
        return val;
    }
};