class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> cnt(26, 0);

        for(char c : tiles) {
            cnt[c - 'A']++;
        }

        return dfs(cnt);
    }

    int dfs(vector<int> &cnt) {
        int ret = 0;
        for(int i = 0; i < cnt.size(); i++) {
            if(cnt[i] == 0) {
                continue;
            }

            ret++;

            cnt[i]--;
            ret += dfs(cnt);
            cnt[i]++;
        }
        return ret;
    }
};