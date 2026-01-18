class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand[2] = {0};
        int cnt[2] = {0};

        for(int n : nums) {
            if(cnt[0] == 0 && cnt[1] == 0) {
                cand[0] = n;
                cnt[0] = 1;
            } else if(cnt[0] == 0) {
                cand[0] = n;
                cnt[0] = 1;
            } else if(cnt[1] == 0) {
                cand[1] = n;
                cnt[1] = 1;
            } else if(cnt[0] >= cnt[1]) {
                --cnt[0];
            } else {
                --cnt[1];
            }
        }

        vector<int> ret;
        cnt[0] = cnt[1] = 0;
        for(int n : nums) {
            if(n == cand[0]) {
                ++cnt[0];
            }
            if(n == cand[1]) {
                ++cnt[1];
            }
        }

        if(cnt[0] > nums.size() / 3) {
            ret.push_back(cand[0]);
        }
        if(cnt[1] > nums.size() / 3 && cand[0] != cand[1]) {
            ret.push_back(cand[1]);
        }

        return ret;
    }
};