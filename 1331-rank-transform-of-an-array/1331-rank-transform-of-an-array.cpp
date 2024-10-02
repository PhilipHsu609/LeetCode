class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> m;

        for(int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }

        int r = 1;
        vector<int> ret(n);
        for(auto &[k, idx] : m) {
            for(int i : idx) {
                ret[i] = r;
            }
            r++;
        }

        return ret;
    }
};