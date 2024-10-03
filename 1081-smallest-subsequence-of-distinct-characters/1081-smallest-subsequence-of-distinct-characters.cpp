class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        unordered_map<char, int> last;

        for(int i = 0; i < n; i++) {
            last[s[i]] = i;
        }

        unordered_set<char> seen;
        stack<char> st;
        for(int i = 0; i < n; i++) {
            if(seen.find(s[i]) != seen.end()) {
                continue;
            }

            while(!st.empty() && st.top() > s[i] && last[st.top()] > i) {
                seen.erase(st.top());
                st.pop();
            }
            seen.insert(s[i]);
            st.push(s[i]);
        }

        string ret;
        while(!st.empty()) {
            ret.push_back(st.top());
            st.pop();
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};