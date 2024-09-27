class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int insert = 0;
        unordered_set<int> seen;

        for(int i = 0; i < n; i++) {
            if(seen.find(nums[i]) == seen.end()) {
                nums[insert] = nums[i];
                insert++;
                seen.insert(nums[i]);
            }
        }

        for(int i = 0; i < n - seen.size(); i++) {
            nums.pop_back();
        }

        return seen.size();
    }
};