class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int zero = 0;
        unordered_set<int> s(begin(arr), end(arr));
        for(int n : arr) {
            if(n != 0 && s.find(n * 2) != s.end()) {
                return true;
            }
            if(n == 0) {
                zero++;
                if(zero > 1) {
                    return true;
                }
            }
        }
        return false;
    }
};