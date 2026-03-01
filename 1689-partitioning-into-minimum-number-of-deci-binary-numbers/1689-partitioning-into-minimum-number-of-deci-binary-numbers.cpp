class Solution {
public:
    int minPartitions(string n) {
        int ret = 0;
        for(char ch : n) {
            ret = max(ret, ch - '0');
        }
        return ret;
    }
};