class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n);

        int ret = false;
        auto dfs = [&](this auto &&self, int x) {
            if(visited[x]) {
                return;
            }

            visited[x] = true;

            if(arr[x] == 0) {
                ret = true;
                return;
            }

            if(x + arr[x] < n) {
                self(x + arr[x]);
            }
            if(x - arr[x] >= 0) {
                self(x - arr[x]);
            }
        };

        dfs(start);

        return ret;
    }
};