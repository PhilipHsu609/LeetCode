class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        int ret = 0;
        int n = nums.size();

        vector<int> current_cost(n);

        for(int b = 30; b >= 0; --b) {
            // test if 2^b is valid
            int target = 1 << b;
            vector<int> new_cost(n);
            for(int i = 0; i < n; ++i) {
                int new_val = nums[i] + current_cost[i];
                int cost = 0;
                if((target & new_val) == 0) {
                    cost = target - ((target - 1) & new_val);
                }
                new_cost[i] = current_cost[i] + cost;
            }

            vector<int> sort_cost(new_cost);
            sort(sort_cost.begin(), sort_cost.end());

            long long sum = 0;
            for(int i = 0; i < m; ++i) {
                sum += sort_cost[i];
            }

            if(sum <= k) {
                ret |= target;
                current_cost = new_cost;
            }
        }

        return ret;
    }
};