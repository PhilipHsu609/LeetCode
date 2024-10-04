class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int sum = accumulate(skill.begin(), skill.end(), 0);
        int target = sum / (n / 2);

        unordered_map<int, int> cnt; // skill -> count
        for(int s : skill) {
            cnt[s]++;
        }

        long long ret = 0;
        while(!cnt.empty()) {
            int s = cnt.begin()->first;
            int c = cnt.begin()->second;

            if(cnt.find(target - s) == cnt.end() || cnt[s] != cnt[target - s]) {
                return -1;
            }

            if(s == target - s) {
                if(c % 2 == 1) {
                    return -1;
                }
                c /= 2;
            }

            ret += static_cast<long long>(s) * (target - s) * c;

            cnt.erase(s);
            cnt.erase(target - s);
        }

        return ret;
    }
};