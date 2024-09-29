class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> cnt;

        vector<string> ret;
        for(auto name : names) {
            if(cnt.find(name) == cnt.end()) {
                cnt[name]++;
            } else {
                while(cnt.find(name + '(' + to_string(cnt[name]) + ')') != cnt.end()) {
                    cnt[name]++;
                }
                name = name + '(' + to_string(cnt[name]) + ')';
                cnt[name]++;
            }

            ret.push_back(name);
        }

        return ret;
    }
};