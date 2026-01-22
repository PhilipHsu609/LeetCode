class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(nums.begin(), nums.end());

        set<pair<long long, int>> s; // {arr[i] + arr[j], i}

        vector<int> prev(n), next(n);
        iota(prev.begin(), prev.end(), -1);
        iota(next.begin(), next.end(), 1);

        int dcnt = 0;
        for(int i = 0; i < n - 1; ++i) {
            if(arr[i] > arr[i + 1]) {
                ++dcnt;
            }
            s.insert({arr[i] + arr[i + 1], i});
        }

        int ret = 0;
        while(dcnt > 0) {
            // p, i, j, q
            int i = s.begin()->second;
            int j = next[i];
            int p = prev[i];
            int q = next[j];

            if(arr[i] > arr[j]) {
                --dcnt;
            }

            // we merge i and j, check if {p, (i + j)} and {(i + j), q} will affect dcnt
            if(p >= 0) {
                if(arr[p] <= arr[i] && arr[p] > arr[i] + arr[j]) {
                    ++dcnt;
                } else if(arr[p] > arr[i] && arr[p] <= arr[i] + arr[j]) {
                    --dcnt;
                }
            }
            if(q < n) {
                if(arr[j] <= arr[q] && arr[i] + arr[j] > arr[q]) {
                    ++dcnt;
                } else if(arr[j] > arr[q] && arr[i] + arr[j] <= arr[q]) {
                    --dcnt;
                }
            }

            // adjust the set s
            int tmpj = arr[j];
            s.erase(s.begin()); // erase {i, j}
            if(p >= 0) {
                s.erase({arr[p] + arr[i], p}); // erase {p, i}
                s.insert({arr[p] + arr[i] + arr[j], p});
            }
            if(q < n) {
                s.erase({arr[j] + arr[q], j}); // erase {j, q}
                s.insert({arr[i] + arr[j] + arr[q], i});
                prev[q] = i;
            }
            next[i] = q;
            arr[i] += arr[j];

            ++ret;
        }

        return ret;
    }
};