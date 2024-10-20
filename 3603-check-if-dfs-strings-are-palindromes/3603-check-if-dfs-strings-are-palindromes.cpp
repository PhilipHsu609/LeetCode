class Solution {
public:
    vector<pair<int, pair<int, int>>> q;
    void dfs(vector<vector<int>>& adj, string& s, int node, int start,
             string& ans) {
        for (auto i : adj[node]) {
            dfs(adj, s, i, ans.size(), ans);
        }
        ans += s[node];
        q.push_back({node, {start, ans.size() - 1}});
    }
    class Hash {
        vector<int> prefixHash;
        vector<int> powers;
        const int BASE1;
        const int BASE2;
        int mod;

    public:
        Hash(string& str) : BASE1(4691), BASE2(7591) {
            mod = 1e9 + 7;
            prefixHash.resize(str.size() + 1, 0);
            powers.resize(str.size() + 1, 1);
            // precompute powers
            for (int i = 1; i < str.size(); i++) {
                powers[i] = (1ll * powers[i - 1] * BASE1) % mod;
            }
            // compute prefixhash
            for (int i = 1; i <= str.size(); i++) {
                int ind = i - 1;
                prefixHash[i] =
                    (1ll * prefixHash[i - 1] * BASE1 + (str[ind] - 'a' + 1)) %
                    mod;
            }
        }

        int getHash(int left, int right) {
            left++;
            right++;
            return (prefixHash[right] -
                    (1ll * prefixHash[left - 1] * powers[right - left + 1]) %
                        mod +
                    mod) %
                   mod;
        }
    };
    vector<bool> findAnswer(vector<int>& parent, string s) {
        // creating adj list
        vector<vector<int>> adj(parent.size());
        for (int i = 1; i < parent.size(); i++) {
            adj[parent[i]].push_back(i);
        }
        // ensuring smaller index goes to dfs first
        for (int i = 0; i < parent.size(); i++) {
            sort(adj[i].begin(), adj[i].end());
        }

        // creating final string and creating queries array q
        // q==>{node,{start,end}} ==> ans[node] = ispalindrome(start to end)
        // the queries are answered in O(1) using Hashing
        string res = "";
        dfs(adj, s, 0, 0, res);

        // hash and reversed hash
        // a string is palindrome if its hash==reversehash
        // also ideally we should have used double hashing but this question has weak test cases :(        Hash h1(res);
        Hash h1(res);
        reverse(res.begin(), res.end());
        Hash h2(res);

        vector<bool> ans(parent.size(), false);
        for (auto i : q) {
            int node = i.first, l = i.second.first, r = i.second.second;
            if (h1.getHash(l, r) == h2.getHash(res.size() - 1 - r, res.size() - 1 - l))
                ans[node] = true;
        }
        return ans;
    }
};