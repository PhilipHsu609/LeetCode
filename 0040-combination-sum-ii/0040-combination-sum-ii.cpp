class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(), cand.end());

        vector<vector<int>> ret;
        vector<int> s;
        helper(0, cand, target, s, ret);

        return ret;
    }

    void helper(int idx, const vector<int> &cand, int target, vector<int> &s, vector<vector<int>> &ret) {
        int n = cand.size();
        
        if(target == 0) {
            ret.push_back(s);
            return;
        }

        if(idx == n) {
            return;
        }

        for(int i = idx; i < n && cand[i] <= target; i++) {
            if(i > idx && cand[i - 1] == cand[i]) {
                continue;
            }
            s.push_back(cand[i]);
            helper(i + 1, cand, target - cand[i], s, ret);
            s.pop_back();
        }
    }
};