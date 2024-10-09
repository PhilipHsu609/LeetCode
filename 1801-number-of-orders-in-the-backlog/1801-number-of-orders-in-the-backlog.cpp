class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> sell;
        priority_queue<array<int, 2>> buy;

        long long ret = 0;
        long long MOD = 1e9 + 7;
        for(const auto &order: orders) {
            int p = order[0], a = order[1], t = order[2];
            ret = (ret + a) % MOD;

            if(t == 1) {
                while(!buy.empty() && a > 0 && buy.top()[0] >= p) {
                    auto [bp, ba] = buy.top(); buy.pop();
                    int num = min(a, ba);

                    a -= num;
                    ba -= num;

                    ret = (ret - 2 * num + MOD) % MOD;

                    if(ba > 0) {
                        buy.push({bp, ba});
                    }
                }

                if(a > 0) {
                    sell.push({p, a});
                }
            } else {
                while(!sell.empty() && a > 0 && sell.top()[0] <= p) {
                    auto [sp, sa] = sell.top(); sell.pop();
                    int num = min(a, sa);

                    a -= num;
                    sa -= num;

                    ret = (ret - 2 * num + MOD) % MOD;

                    if(sa > 0) {
                        sell.push({sp, sa});
                    }
                }
                
                if(a > 0) {
                    buy.push({p, a});
                }
            }
        }

        return ret;
    }
};