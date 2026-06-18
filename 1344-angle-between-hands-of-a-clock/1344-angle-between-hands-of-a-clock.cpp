class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = hour * 30.0 + minutes / 2.0;
        double m = minutes * 6.0;
        double dif = abs(h - m);
        return min(dif, 360.0 - dif);
    }
};