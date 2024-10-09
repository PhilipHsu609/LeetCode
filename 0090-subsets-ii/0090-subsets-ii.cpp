class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> s;
        helper(0, nums, s, ret);
        return ret;
    }

    void helper(int idx, const vector<int> &nums, vector<int> &s, vector<vector<int>> &ret) {
        ret.push_back(s);

        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i - 1] == nums[i]) {
                continue;
            }

            s.push_back(nums[i]);
            helper(i + 1, nums, s, ret);
            s.pop_back();
        }
    }
};