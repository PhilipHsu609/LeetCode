class Solution {
public:
    unordered_map<int, int> memo;

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return helper(price, special, comp(needs));
    }

    int helper(const vector<int> &price, const vector<vector<int>> &special, int state) {
        if(memo.find(state) != memo.end()) {
            return memo[state];
        }

        vector<int> needs = decomp(state);
        int n = price.size();
        int ret = 0;
        for(int i = 0; i < n; ++i) {
            ret += price[i] * needs[i];
        }

        for(const auto &s : special) {
            bool canuse = true;
            vector<int> next(needs);
            for(int i = 0; i < n; ++i) {
                if(needs[i] < s[i]) {
                    canuse = false;
                    break;
                }
                next[i] -= s[i];
            }
            if(canuse) {
                ret = min(ret, helper(price, special, comp(next)) + s.back());
            }
        }

        return memo[state] = ret;
    }

    int comp(const vector<int> &needs) {
        int n = needs.size();
        int state = (1 << 4) - 1;
        for(int i = 0; i < n; ++i) {
            state <<= 4;
            state |= needs[i];
        }
        return state;
    }

    vector<int> decomp(int state) {
        vector<int> ret;
        int mask = (1 << 4) - 1;
        while(state != mask) {
            ret.push_back(state & mask);
            state >>= 4;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};