class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(), bank.end());
        unordered_set<string> visited;

        if(bankset.count(endGene) == 0) {
            return -1;
        }

        queue<pair<string, int>> q;
        q.push({startGene, 0});

        while(!q.empty()) {
            auto [u, t] = q.front();
            q.pop();

            if(u == endGene) {
                return t;
            }

            for(const auto &b : bank) {
                if(visited.count(b) == 0 && validMutation(u, b)) {
                    q.push({b, t + 1});
                    visited.insert(b);
                }
            }
        }

        return -1;
    }

    bool validMutation(string_view s1, string_view s2) {
        if(s1.length() != s2.length()) {
            return false;
        }
        int diff = 0;
        for(int i = 0; i < s1.length(); ++i) {
            if(s1[i] != s2[i]) {
                ++diff;
            }
        }
        return diff == 1;
    }
};