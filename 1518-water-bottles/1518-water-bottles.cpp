class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = numBottles;
        while(empty / numExchange > 0) {
            numBottles += empty / numExchange;
            empty -= (empty / numExchange) * (numExchange - 1);
        }
        return numBottles;
    }
};