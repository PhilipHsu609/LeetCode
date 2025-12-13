class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;

        int p = 0;
        for(int i = 1; i <= n && p < target.size(); i++) {
            if(target[p] == i) {
                ans.push_back("Push");
                p++;

                if(p == target.size() && i == target.size())
                    break;

            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }

        return ans;
    }
};