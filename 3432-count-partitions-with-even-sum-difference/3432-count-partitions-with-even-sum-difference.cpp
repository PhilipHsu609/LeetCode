class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;
        int even = 0;
        int odd = 0;

        for(int n : nums) {
            total += n;
            if(total % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }

        return total % 2 == 0 ? even - 1 + odd : 0;
    }
};

// a - (sum - a) = 2 * a - sum
// (sum - a) - a = sum - 2 * a