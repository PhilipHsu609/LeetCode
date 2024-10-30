class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        auto l = LIS(nums);
        auto r = LISrev(nums);

        int n = nums.size();
        int len = 0;
        for(int i = 0; i < n; i++) {
            len = max(len, l[i] + r[i] + 1);
        }

        return n - len;
    }

    vector<int> LIS(const vector<int> &nums) {
        int n = nums.size();
        vector<int> ret(n);

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    ret[i] = max(ret[i], ret[j] + 1);
                }
            }
        }

        return ret;
    }

    vector<int> LISrev(const vector<int> &nums) {
        int n = nums.size();
        vector<int> ret(n);

        for(int i = n - 2; i >= 0; i--) {
            for(int j = n - 1; j > i; j--) {
                if(nums[j] < nums[i]) {
                    ret[i] = max(ret[i], ret[j] + 1);
                }
            }
        }

        return ret;
    }
};