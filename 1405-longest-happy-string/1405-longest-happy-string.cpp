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

        int n = a + b + c;
        for(int i = 0; i < n; i++) {
            if(pq.empty()) {
                break;
            }

            auto [f1, c1] = pq.top(); pq.pop();
            if(i > 1 && c1 == ret[i - 1] && c1 == ret[i - 2]) {
                if(pq.empty()) {
                    break;
                }
                auto [f2, c2] = pq.top(); pq.pop();
                ret += c2;
                if(f2 > 1)
                    pq.push({f2 - 1, c2});
                pq.push({f1, c1});
            } else {
                ret += c1;
                if(f1 > 1)
                    pq.push({f1 - 1, c1});
            }
        }

        return ret;
    }
};