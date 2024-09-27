class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ret;

        if(n < 4) {
            return ret;
        }

        sort(nums.begin(), nums.end());

        for(int a = 0; a < n; a++) {
            
            if(nums[a] * 4ll > target) {
                break;
            }
            
            if(a > 0 && nums[a - 1] == nums[a]) {
                continue;
            }

            for(int b = a + 1; b < n - 2; b++) {

                if(nums[a] + nums[b] * 3ll > target) {
                    break;
                }

                if(b > a + 1 && nums[b - 1] == nums[b]) {
                    continue;
                }

                int c = b + 1, d = n - 1;

                if(nums[a] + nums[b] + nums[c] * 2ll > target) {
                    break;
                }

                while(c < d) {
                    long long sum = (long long)nums[a] + nums[b] + nums[c] + nums[d];

                    if(sum == target) {
                        ret.push_back({nums[a], nums[b], nums[c], nums[d]});
                    }

                    if(sum >= target) {
                        d--;
                        while(d > 0 && nums[d] == nums[d + 1]) {
                            d--;
                        }
                    } else {
                        c++;
                        while(c < n && nums[c - 1] == nums[c]) {
                            c++;
                        }
                    }
                }
            }
        }

        return ret;
    }
};