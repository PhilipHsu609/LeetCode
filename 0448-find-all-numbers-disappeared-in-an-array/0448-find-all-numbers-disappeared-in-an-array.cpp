class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> ret;
        for(int i = 1; i <= nums.size(); ++i) {
            if(s.count(i) == 0) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

// 1 2 2 3 3 4 7 8
// 1 2 3 4 5 6 7 8