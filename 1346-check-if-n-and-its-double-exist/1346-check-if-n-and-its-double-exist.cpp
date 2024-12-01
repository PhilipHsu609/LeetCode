class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s(begin(arr), end(arr));
        for(int n : arr) {
            if(n != 0 && s.find(n * 2) != s.end()) {
                return true;
            }
        }
        return false;
    }
};