class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;

        int ret = 0;
        for(int start = 0, end = 0; end < fruits.size(); ++end) {
            ++freq[fruits[end]];

            if(freq.size() > 2) {
                --freq[fruits[start]];
                if(freq[fruits[start]] == 0) {
                    freq.erase(fruits[start]);
                }
                ++start;
            }

            ret = max(ret, end - start + 1);
        }

        return ret;
    }
};