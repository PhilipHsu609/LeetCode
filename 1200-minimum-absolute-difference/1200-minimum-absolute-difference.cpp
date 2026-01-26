class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int mind = INT_MAX;

        vector<vector<int>> ret;
        for(int i = 1; i < n; ++i) {
            int diff = arr[i] - arr[i - 1];
            if(diff < mind) {
                mind = diff;
                ret.clear();
            }
            if(diff == mind) {
                ret.push_back({arr[i - 1], arr[i]});
            }
        }
        return ret;
    }
};