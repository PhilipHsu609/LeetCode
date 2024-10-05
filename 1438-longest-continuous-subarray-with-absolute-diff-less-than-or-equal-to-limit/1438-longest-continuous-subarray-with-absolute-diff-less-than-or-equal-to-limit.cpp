class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minq, maxq;

        int start = 0, end = 0;
        for(; end < nums.size(); end++) {
            while(!minq.empty() && minq.back() > nums[end]) {
                minq.pop_back();
            }
            while(!maxq.empty() && maxq.back() < nums[end]) {
                maxq.pop_back();
            }
            minq.push_back(nums[end]);
            maxq.push_back(nums[end]);
            if(maxq.front() - minq.front() > limit) {
                if(maxq.front() == nums[start]) {
                    maxq.pop_front();
                }
                if(minq.front() == nums[start]) {
                    minq.pop_front();
                }
                start++;
            }
        }

        return end - start;
    }
};