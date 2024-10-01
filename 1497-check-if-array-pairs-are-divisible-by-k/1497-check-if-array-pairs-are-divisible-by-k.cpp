class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> m;

        for(int n : arr) {
            int x = ((n % k) + k) % k;
            m[x]++;
        }

        for(int i = 1; i <= k / 2; i++) {
            if(m[i] != m[k - i]) {
                return false;
            }
        }

        return m[0] % 2 == 0;
    }
};