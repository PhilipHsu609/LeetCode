class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int i = 0;
        for(const auto &m : meetings) {
            if(i < m[0]) {
                i = m[1];
                days -= m[1] - m[0] + 1;
            } else if(m[0] <= i && i <= m[1]) {
                days -= m[1] - i;
                i = m[1];
            }
        }

        return days;
    }
};