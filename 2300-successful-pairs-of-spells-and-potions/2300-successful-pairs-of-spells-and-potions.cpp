class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        sort(potions.begin(), potions.end());    

        vector<int> ret;

        for(int spell : spells) {
            long long need = ceil(success / static_cast<double>(spell));
            if(need > 1e5) {
                ret.push_back(0);
                continue;
            }
            auto it = lower_bound(potions.begin(), potions.end(), need);
            ret.push_back(distance(it, potions.end()));
        }

        return ret;
    }
};