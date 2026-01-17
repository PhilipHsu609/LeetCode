class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> side;
        for(int i = 0; i < hFences.size(); ++i) {
            for(int j = i + 1; j < hFences.size(); ++j) {
                side.insert(hFences[j] - hFences[i]);
            }
        }

        int maxside = 0;
        for(int i = 0; i < vFences.size(); ++i) {
            for(int j = i + 1; j < vFences.size(); ++j) {
                if(side.count(vFences[j] - vFences[i]) != 0) {
                    maxside = max(maxside, vFences[j] - vFences[i]);
                }
            }
        }

        int MOD = 1e9 + 7;
        int area = static_cast<int>((1LL * maxside * maxside) % MOD);

        return area == 0 ? -1 : area;
    }
};