class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> freq;

        for(int a : ages) {
            ++freq[a];
        }

        int ret = 0;
        for(auto [k1, v1] : freq) {
            for(auto [k2, v2] : freq) {
                if(canSend(k1, k2)) {
                    if(k1 == k2) {
                        ret += v1 * (v1 - 1);
                    } else {
                        ret += v1 * v2;
                    }
                }
            }
        }

        return ret;
    }

    bool canSend(int x, int y) {
        return !(y <= 0.5 * x + 7 || y > x || y > 100 && x < 100);
    }
};