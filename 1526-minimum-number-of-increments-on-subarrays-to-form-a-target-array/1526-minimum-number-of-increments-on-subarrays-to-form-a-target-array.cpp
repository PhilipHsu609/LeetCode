class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ret = target[0];
        int n = target.size();
        for(int i = 1; i < n; i++) {
            if(target[i - 1] < target[i]) {
                ret += target[i] - target[i - 1];
            }
        }
        return ret;
    }
};