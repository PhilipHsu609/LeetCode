class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n);

        for(const auto &b : bookings) {
            diff[b[0] - 1] += b[2];
            if(b[1] < n) {
                diff[b[1]] -= b[2];
            }
        }

        for(int i = 1; i < n; ++i) {
            diff[i] += diff[i - 1];
        }

        return diff;
    }
};