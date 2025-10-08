class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        sort(potions.begin(), potions.end());    

        vector<int> ret;

        for(int spell : spells) {
            long long need = (success + spell - 1) / spell;
            auto it = lower_bound(potions.begin(), potions.end(), need);
            ret.push_back(distance(it, potions.end()));
        }

        return ret;
    }
};