class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0, r = static_cast<long long>(cars) * cars * (*max_element(ranks.begin(), ranks.end()));

        while(l < r) {
            long long mid = l + (r - l) / 2;

            if(good(ranks, mid, cars)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

    bool good(const vector<int> &ranks, long long time, int cars) {
        int repaired = 0;

        for(int r : ranks) {
            // r * n * n <= t
            // n * n <= t / r
            // n <= sqrt(t / r)
            repaired += static_cast<int>(sqrt(time / static_cast<double>(r)));

            if(repaired >= cars) {
                return true;
            }
        }

        return false;
    }
};