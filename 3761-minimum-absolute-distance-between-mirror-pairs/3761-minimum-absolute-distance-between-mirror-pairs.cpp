class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> last;

        int ret = n;
        for(int i = 0; i < n; ++i) {
            if(last.find(nums[i]) != last.end()) {
                ret = min(ret, i - last[nums[i]]);
            }
            last[rev(nums[i])] = i;
        }

        return ret == n ? -1 : ret;
    }

    int rev(int x) {
        int ret = 0;
        while(x > 0) {
            ret *= 10;
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }
};