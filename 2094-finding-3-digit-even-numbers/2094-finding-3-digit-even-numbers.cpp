class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> cnt(10);

        for(int d : digits) {
            cnt[d]++;
        }

        vector<int> ret;
        helper(0, 0, cnt, ret);
        sort(ret.begin(), ret.end());

        return ret;
    }

    void helper(int cur, int level, vector<int> &cnt, vector<int> &ret) {
        if(level == 3) {
            if(cur % 2 == 0 && cur >= 100) {
                ret.push_back(cur);
            }
            return;
        }

        for(int i = 0; i < 10; i++) {
            if(cnt[i] == 0) {
                continue;
            }

            cnt[i]--;
            helper(cur * 10 + i, level + 1, cnt, ret);
            cnt[i]++;
        }
    }
};