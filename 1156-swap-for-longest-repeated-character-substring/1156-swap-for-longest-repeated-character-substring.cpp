class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        vector<int> freq(26);
        vector<pair<char, int>> enc;

        enc.push_back({text[0], 1});
        ++freq[text[0] - 'a'];

        for(int i = 1; i < n; ++i) {
            if(text[i - 1] == text[i]) {
                ++(enc.back().second);
            } else {
                enc.push_back({text[i], 1});
            }
            ++freq[text[i] - 'a'];
        }

        int ret = 0;
        int m = enc.size();
        for(int i = 0; i < m; ++i) {
            ret = max(ret, enc[i].second);

            if(freq[enc[i].first - 'a'] > enc[i].second) {
                ret = max(ret, enc[i].second + 1);
            }

            if(i + 2 < m && enc[i + 1].second == 1 && enc[i].first == enc[i + 2].first) {
                ret = max(ret, enc[i].second + enc[i + 2].second);

                if(freq[enc[i].first - 'a'] > enc[i].second + enc[i + 2].second) {
                    ret = max(ret, enc[i].second + enc[i + 2].second + 1);
                }
            }
        }

        return ret;
    }
};

/*
..aaaa...a..
..aaaaa.....
..aaaa.aaaa.
*/