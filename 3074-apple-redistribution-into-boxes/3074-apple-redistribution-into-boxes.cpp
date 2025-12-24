class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for(int a : apple) {
            sum += a;
        }

        sort(capacity.rbegin(), capacity.rend());

        int ret = 0;
        for(int i = 0; i < capacity.size(); ++i) {
            if(sum <= 0) {
                break;
            }
            sum -= capacity[i];
            ++ret;
        }

        return ret;
    }
};