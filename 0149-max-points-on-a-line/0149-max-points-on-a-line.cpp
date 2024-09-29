class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if(n < 3) {
            return n;
        }

        int ret = 0;
        for(int i = 0; i < n; i++) {
            unordered_map<string, int> cnt;
            int dup = 0;

            for(int j = 0; j < n; j++) {
                if(i == j) {
                    continue;
                }

                if(points[i] == points[j]) {
                    dup++;
                    continue;
                }

                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int g = gcd(dx, dy);

                dx /= g;
                dy /= g;

                string key = to_string(dx) + "_" + to_string(dy);
                cnt[key]++;
            }

            for(const auto &[k, v] : cnt) {
                ret = max(ret, v + dup + 1);
            }
        }

        return ret;
    }
};