class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> freq;

        int maxf = 0;
        int maxb = 0;
        for(int b : barcodes) {
            ++freq[b];
            if(freq[b] > maxf) {
                maxf = freq[b];
                maxb = b;
            }
        }

        vector<int> ret(barcodes.size());

        int i = 0;
        while(freq[maxb]-- > 0) {
            ret[i] = maxb;
            i += 2;
        }

        for(auto [k, v] : freq) {
            while(v-- > 0) {
                if(i >= ret.size()) {
                    i = 1;
                }
                ret[i] = k;
                i += 2;
            }
        }

        return ret;
    }
};