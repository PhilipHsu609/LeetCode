class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        set<pair<int, int>> s;
        vector<int> prev(n), next(n);

        iota(prev.begin(), prev.end(), -1);
        iota(next.begin(), next.end(), 1);

        int dcnt = 0;
        for(int i = 0; i < n - 1; ++i) {
            if(nums[i] > nums[i + 1]) {
                ++dcnt;
            }
            s.insert({nums[i] + nums[i + 1], i});
        }

        int ret = 0;
        while(dcnt > 0) {
            int i = s.begin()->second;
            int j = next[i];
            int p = prev[i];
            int q = next[j];

            if(nums[i] > nums[i + 1]) {
                --dcnt;
            }

            if(p >= 0) {
                if(nums[p] > nums[i] && nums[p] <= nums[i] + nums[j]) {
                    --dcnt;
                } else if(nums[p] <= nums[i] && nums[p] > nums[i] + nums[j]) {
                    ++dcnt;
                }
            }
            if(q < n) {
                if(nums[j] > nums[q] && nums[i] + nums[j] <= nums[q]) {
                    --dcnt;
                } else if(nums[j] <= nums[q] && nums[i] + nums[j] > nums[q]) {
                    ++dcnt;
                }
            }

            s.erase(s.begin());
            if(p >= 0) {
                s.erase({nums[p] + nums[i], p});
                s.insert({nums[p] + nums[i] + nums[j], p});
            }
            if(q < n) {
                s.erase({nums[j] + nums[q], j});
                s.insert({nums[i] + nums[j] + nums[q], i});
                prev[q] = i;
            }
            next[i] = q;
            nums[i] += nums[j];
            ++ret;
        }

        return ret;
    }
};