class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<int> idx;

        for(int i = 0; i < n; ++i) {
            if(validCode(code[i]) && validBiz(businessLine[i]) && isActive[i]) {
                idx.push_back(i);
            }
        }

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if(businessLine[a] == businessLine[b]) {
                return code[a] < code[b];
            }
            return businessLine[a] < businessLine[b];
        });

        vector<string> ret;
        for(int i : idx) {
            ret.push_back(code[i]);
        }

        return ret;
    }

    bool validCode(const string &code) {
        if(code.empty()) {
            return false;
        }
        for(char c : code) {
            if(isalnum(c) == 0 && c != '_') {
                return false;
            }
        }
        return true;
    }

    bool validBiz(const string &biz) {
        static const unordered_set<string> s{"electronics", "grocery", "pharmacy", "restaurant"};
        return s.count(biz) != 0;
    }
};