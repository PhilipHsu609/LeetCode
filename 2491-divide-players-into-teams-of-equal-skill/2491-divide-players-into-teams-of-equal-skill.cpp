class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if(n == 2) {
            return static_cast<long long>(skill[0]) * skill[1];
        }

        int sum = accumulate(skill.begin(), skill.end(), 0);

        if(sum % 2 == 1) {
            return -1;
        }

        int target = sum * 2 / n;
        sort(skill.begin(), skill.end());

        int l = 0, r = n - 1;
        long long ret = 0;
        while(l < r) {
            if(skill[l] + skill[r] != target) {
                return -1;
            }
            ret += static_cast<long long>(skill[l]) * skill[r];
            l++, r--;
        }

        return ret;
    }
};