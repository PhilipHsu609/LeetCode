class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        int n = s.length();
        int maxf = 0;
        char maxc = ' ';
        for(char c : s) {
            ++freq[c];
            if(freq[c] > maxf) {
                maxf = freq[c];
                maxc = c;
            }
        } 

        if(maxf > (n + 1) / 2) {
            return "";
        }
        
        int i = 0;
        string ret(n, ' ');
        while(freq[maxc]-- > 0) {
            ret[i] = maxc;
            i += 2;
        }

        for(auto [k, v] : freq) {
            while(v-- > 0) {
                if(i >= n) {
                    i = 1;
                }
                ret[i] = k;
                i += 2;
            }
        }

        return ret;
    }
};