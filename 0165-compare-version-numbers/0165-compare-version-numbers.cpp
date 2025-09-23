class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.length(), n = version2.length();
        int i = 0, j = 0;

        while(i < m || j < n) {
            int rv1 = 0, rv2 = 0;

            while(i < m && version1[i] != '.') {
                rv1 = 10 * rv1 + (version1[i] - '0');
                i++;
            }

            while(j < n && version2[j] != '.') {
                rv2 = 10 * rv2 + (version2[j] - '0');
                j++;
            }

            if(rv1 < rv2) {
                return -1;
            } else if(rv1 > rv2) {
                return 1;
            }

            i++, j++;
        }

        return 0;
    }
};