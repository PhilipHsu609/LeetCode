class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> sh(n + 1);

        for(const auto &shift : shifts) {
            if(shift[2] == 1) {
                sh[shift[0]] += 1;
                sh[shift[1] + 1] -= 1;
            } else {
                sh[shift[0]] -= 1;
                sh[shift[1] + 1] += 1; 
            }
        }

        int sh_size = 0;
        for(int i = 0; i < n; i++) {
            sh_size += sh[i];
            s[i] = ((s[i] - 'a') + sh_size + 26) % 26 + 'a';
        }

        return s;
    }
};