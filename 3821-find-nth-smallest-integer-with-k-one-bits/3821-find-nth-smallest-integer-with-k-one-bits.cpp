class Solution {
public:
    long long nthSmallest(long long n, int k) {
        long long result = 0;
        
        // We need to determine the position of k bits, one by one.
        // We start determining the highest (MSB) remaining bit.
        while (k > 0) {
            // The smallest possible position for the k-th bit is (k-1)
            // (e.g., if k=1, smallest pos is 0).
            int pos = k - 1;
            
            // cnt stores nCr(pos, k-1)
            // Initially nCr(k-1, k-1) = 1
            long long cnt = 1; 
            
            // While n is larger than the number of combinations with MSB at 'pos',
            // it means the MSB must be at a higher position.
            while (n > cnt) {
                n -= cnt; // Skip these combinations
                pos++;
                
                // Update combinations iteratively to avoid factorials:
                // nCr(pos, r) = nCr(pos-1, r) * pos / (pos - r)
                // Here r = k-1
                cnt = cnt * pos / (pos - k + 1);
            }
            
            // We found the correct position 'pos' for the current k-th bit
            result |= (1LL << pos);
            
            // Now we look for the next bit (k-1 bits remaining)
            k--;
        }
        
        return result;
    }
};