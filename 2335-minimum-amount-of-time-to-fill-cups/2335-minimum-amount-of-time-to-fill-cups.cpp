class Solution {
public:
    int fillCups(vector<int>& amount) {
        int sum = accumulate(amount.begin(), amount.end(), 0);
        int maxi = *max_element(amount.begin(), amount.end());
        if(maxi > sum / 2) {
            return maxi;
        }
        return (sum + 1) / 2;
    }
};