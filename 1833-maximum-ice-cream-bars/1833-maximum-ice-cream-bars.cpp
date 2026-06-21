class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        ranges::sort(costs);
        int i = 0;
        while(i < costs.size() && coins >= costs[i]) {
            coins -= costs[i++];
        }
        return i;
    }
};