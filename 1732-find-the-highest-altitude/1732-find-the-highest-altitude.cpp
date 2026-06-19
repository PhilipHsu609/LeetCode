class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0;
        int ret = 0;
        for(int g : gain) {
            alt += g;
            ret = max(ret, alt);
        }
        return ret;
    }
};