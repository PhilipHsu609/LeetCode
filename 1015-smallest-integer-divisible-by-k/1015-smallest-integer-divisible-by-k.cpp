class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int r = 0;
        int i = 0;
        unordered_set<int> seen;
        while(i <= k) {
            i++;
            r = (r * 10 + 1) % k;
            if(r == 0) {
                break;
            }
            if(seen.count(r) == 1) {
                return -1;
            }
            seen.insert(r);
        }
        return i;
    }
};