class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;

        for(int num : nums) {
            m[num] += num;
        }

        int take = 0, skip = 0;
        int last_num = -1;
        for(const auto &p : m) {
            if(last_num != -1 && p.first - 1 == last_num) {
                // nums[i]-1 exist
                // since nums[i]-1 exist, so the `take` variable store the best result for the sub-problem where nums[i] get removed
                // we can only pick one of nums[i]-1 and nums[i]
                // choose the maximum one
                int temp = max(skip + p.second, take);
                skip = take;
                take = temp;
            } else {
                // nums[i]-1 not exist
                skip = take;
                take += p.second;
            }
            last_num = p.first;
        }

        return max(take, skip);
    }
};