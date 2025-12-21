class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();

        vector<int> set;
        vector<vector<int>> ret;

        auto helper = [&](auto helper, int mask) {
            if(set.size() == n) {
                ret.push_back(set);
                return;
            }

            unordered_set<int> pick;
            for(int j = 0; j < n; j++) {
                if(!pick.count(nums[j]) && (mask & (1 << j)) == 0) {
                    set.push_back(nums[j]);
                    helper(helper, mask | (1 << j));
                    set.pop_back();

                    pick.insert(nums[j]);
                }
            }
            return;
        };

        helper(helper, 0);
        return ret;
    }
};