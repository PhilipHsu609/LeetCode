class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ret = 0;
        
        for(int start = 0, end = 1; end < n + k - 1; end++) {
            if(colors[(end - 1 + n) % n] == colors[end % n]) {
                start = end;
            }

            if(end - start + 1 == k) {
                ret++;
                start++;
            }
        }

        return ret;
    }
};