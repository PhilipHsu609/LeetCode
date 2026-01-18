class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ret;

        priority_queue<pair<int, char>> pq;
        if(a > 0)
            pq.push({a, 'a'});
        if(b > 0)
            pq.push({b, 'b'});
        if(c > 0)
            pq.push({c, 'c'});

        while(!pq.empty()) {
            auto [cnt, ch] = pq.top();
            pq.pop();

            int n = ret.size();
            if(n > 1 && ret[n - 2] == ch && ret[n - 1] == ch) {
                // cannot use ch
                if(pq.empty()) {
                    break;
                }
                // use the 2nd most instead
                auto [cnt2, ch2] = pq.top();
                pq.pop();

                ret.push_back(ch2);
                if(--cnt2 > 0) {
                    pq.push({cnt2, ch2});
                }
            } else {
                ret.push_back(ch);
                --cnt;
            }

            if(cnt > 0) {
                pq.push({cnt, ch});
            }
        }

        return ret;
    }
};