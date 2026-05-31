class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long total = mass;
        for(int a : asteroids) {
            if(total < a) {
                return false;
            }
            total += a;
        }
        return true;
    }
};