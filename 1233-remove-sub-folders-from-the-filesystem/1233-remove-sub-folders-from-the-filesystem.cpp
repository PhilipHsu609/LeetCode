class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        int n = folder.size();
        vector<string> ret;
        ret.push_back(folder.front());

        for(int i = 1; i < n; i++) {
            string root = ret.back() + '/';
            string prefix = folder[i].substr(0, root.length());
            if(root != prefix) {
                ret.push_back(folder[i]);
            }
        }

        return ret;
    }
};