class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> ret;
        unordered_map<int, int> freq;
        set<array<int, 2>> top, bot;

        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            // check nums[i] is in top or bot
            long long f = freq[nums[i]];
            int v = nums[i];
            if(f > 0) {
                if(top.find({f, v}) != top.end()) {
                    top.erase({f, v});
                    sum -= f * v;
                } else {
                    bot.erase({f, v});
                }
            }

            // add nums[i] to top
            freq[nums[i]]++;
            top.insert({f + 1, v});
            sum += (f + 1) * v;

            // fix top if more than x element
            if(top.size() > x) {
                // move the least frequent in top to bot
                auto it = top.begin();
                sum -= (*it)[0] * (*it)[1];
                bot.insert({(*it)[0], (*it)[1]});
                top.erase(it);
            }
            
            // shrink the sliding window
            if(i >= k) {
                // remove nums[i - k]
                f = freq[nums[i - k]];
                v = nums[i - k];
                if(top.find({f, v}) != top.end()) {
                    top.erase({f, v});
                    sum -= f * v;
                } else {
                    bot.erase({f, v});
                }

                if(f > 1) {
                    bot.insert({f - 1, v});
                }

                freq[nums[i - k]]--;

                if(top.size() < x && !bot.empty()) {
                    auto it = prev(bot.end(), 1);
                    sum += (*it)[0] * (*it)[1];
                    top.insert({(*it)[0], (*it)[1]});
                    bot.erase(it);
                }
            }

            if(i >= k - 1) {
                ret.push_back(sum);
            }
        }

        return ret;
    }
};