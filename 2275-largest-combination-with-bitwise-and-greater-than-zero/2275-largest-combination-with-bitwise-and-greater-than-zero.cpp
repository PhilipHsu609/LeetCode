class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ret = 0;
        vector<int> cnt(32, 0);

        for(int num : candidates) {
            for(int i = 0; i < 32; i++) {
                if((num & (1 << i)) != 0) {
                    cnt[i]++;
                }
            }
        }

        for(int i = 0; i < 32; i++) {
            ret = max(ret, cnt[i]);
        }

        return ret;
    }
};