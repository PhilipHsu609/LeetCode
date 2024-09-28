class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        while(l < r) {
            int mid = l + (r - l) / 2;

            int sum = 0, count = 1;
            for(int w : weights) {
                if(w > mid) {
                    // impossible
                    count = days + 1;
                    break;
                }
                sum += w;
                if(sum > mid) {
                    count++;
                    sum = w;
                }
            }

            if(count <= days) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};