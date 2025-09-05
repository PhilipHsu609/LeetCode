class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> cur;
        helper(candidates, cur, 0, target, ret);
        return ret;        
    }

    void helper(const vector<int> &cand, vector<int> &cur, int i, int target, vector<vector<int>> &ret) {
        int n = cand.size();

        if(i == n || target == 0) {
            if(target == 0) {
                ret.push_back(cur);
            }
            return;
        }

        helper(cand, cur, i + 1, target, ret);
        for(int j = 1; j <= target / cand[i]; j++) {
            cur.push_back(cand[i]);
            helper(cand, cur, i + 1, target - j * cand[i], ret);
        }
        for(int j = 1; j <= target / cand[i]; j++) {
            cur.pop_back();
        }
    }
};