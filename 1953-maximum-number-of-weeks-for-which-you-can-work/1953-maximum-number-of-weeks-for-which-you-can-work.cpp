class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum = 0;
        long long maxi = 0;
        for(int m : milestones) {
            sum += m;
            maxi = max(maxi, 1LL * m);
        }

        if(maxi > sum / 2) {
            return (sum - maxi) * 2 + 1;
        }
        return sum;
    }
};