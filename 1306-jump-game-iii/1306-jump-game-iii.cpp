class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n);

        return dfs(start, arr, visited);
    }

    bool dfs(int idx, const vector<int> &arr, vector<int> &visited) {
        int n = arr.size();

        if(idx < 0 || idx >= n || visited[idx] == 1) {
            return false;
        }

        if(arr[idx] == 0) {
            return true;
        }

        visited[idx] = 1;

        return dfs(idx + arr[idx], arr, visited) || dfs(idx - arr[idx], arr, visited);
    }
};