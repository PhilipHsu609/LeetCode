class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> m;

        for(int n : nums) {
            if(m.find(n) != m.end()) {
                m.erase(n);
            } else {
                m.insert(n);
            }
        }

        return m.empty();
    }
};