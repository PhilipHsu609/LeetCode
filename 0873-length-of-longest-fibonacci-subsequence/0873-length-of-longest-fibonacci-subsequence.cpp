class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> s(arr.begin(), arr.end());

        int ret = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int a = arr[i], b = arr[j], l = 2;
                while(s.find(a + b) != s.end()) {
                    b = a + b;
                    a = b - a;
                    l++;
                }
                ret = max(ret, l);
            }
        }

        return ret > 2 ? ret : 0;
    }
};