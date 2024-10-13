class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq; // {val, row, col}
        vector<int> ret(2);

        int right = numeric_limits<int>::min();
        int left = numeric_limits<int>::max();
        for(int i = 0; i < k; i++) {
            left = min(left, nums[i][0]);
            right = max(right, nums[i][0]);
            pq.push({nums[i][0], i, 0});
        }

        ret[0] = left;
        ret[1] = right;

        while(!pq.empty()) {
            auto [left, row, col] = pq.top();
            pq.pop();

            if(right - left < ret[1] - ret[0]) {
                ret[0] = left;
                ret[1] = right;
            }

            if(col == nums[row].size() - 1) {
                break;
            }

            right = max(right, nums[row][col + 1]);
            pq.push({nums[row][col + 1], row, col + 1});
        }

        return ret;
    }
};