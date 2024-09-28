class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) : arr{arr} {
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        int range = right - left + 1;

        for(int i = 0; i < 20; i++) {
            int cand = arr[left + rand() % range];

            int l = lower_bound(m[cand].begin(), m[cand].end(), left) - m[cand].begin();
            int r = upper_bound(m[cand].begin(), m[cand].end(), right) - m[cand].begin();

            if(r - l >= threshold) {
                return cand;
            }
        }

        return -1;
    }

    unordered_map<int, vector<int>> m; // x -> position of xs
    vector<int> arr;
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */