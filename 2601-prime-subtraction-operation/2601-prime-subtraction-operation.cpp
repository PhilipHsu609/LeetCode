class Solution {
public:
    vector<bool> sieve;

    void buildSieve() {
        sieve.resize(1001, true);
        
        for(int i = 2; i * i <= 1000; i++) {
            if(!sieve[i]) {
                continue;
            }

            for(int j = i * i; j <= 1000; j += i) {
                sieve[j] = false;
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        buildSieve();

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                continue;
            }

            int p = 2;
            while(nums[i] - p >= nums[i + 1]) {
                p = nextPrime(p);
            }

            if(nums[i] <= p) {
                return false;
            }

            nums[i] -= p;
        }

        return true;
    }

    int nextPrime(int n) {
        while(true) {
            n++;
            if(sieve[n]) {
                break;
            }
        }
        return n;
    }
};