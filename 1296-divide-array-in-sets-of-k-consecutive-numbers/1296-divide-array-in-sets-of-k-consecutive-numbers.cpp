class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) {
            return false;
        }

        map<int, int> m; // num -> count;

        for(int num : nums) {
            m[num]++;
        }

        for(int i = 0; i < n / k; i++) {
            int x = m.begin()->first;
            if(--m[x] == 0) {
                m.erase(x);
            }

            for(int j = 1; j < k; j++) {
                if(m.find(x + 1) == m.end()) {
                    return false;
                }
                if(--m[x + 1] == 0) {
                    m.erase(x + 1);
                }
                x++;
            }
        }

        return true;
    }
};