class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ret = 0;
        multiset<int> ms;
        int start, end;
        for(start = 0, end = 0; end < nums.size(); end++) {
            ms.insert(nums[end]);
            if(*ms.rbegin() - *ms.begin() > limit) {
                ms.erase(ms.find(nums[start]));
                start++;
            }
        }

        return end - start;
    }
};