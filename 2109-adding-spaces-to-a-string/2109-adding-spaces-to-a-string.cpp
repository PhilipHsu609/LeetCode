class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        int m = spaces.size();
        int sidx = 0;
        string ret;

        for(int i = 0; i < n; i++) {
            if(sidx < m && i == spaces[sidx]) {
                ret += ' ';
                sidx++;
            }
            ret += s[i];
        }

        return ret;
    }
};