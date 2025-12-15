class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int start = 0;

        while(cnt < n) {
            int cur = start;
            int last = nums[start];

            do {
                int next = (cur + k) % n;
                swap(last, nums[next]);
                cur = next;
                ++cnt;
            } while(cur != start);

            ++start;
        }
    }
};