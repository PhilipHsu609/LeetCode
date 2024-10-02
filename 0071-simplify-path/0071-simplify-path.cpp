class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;

        int i = 0;
        int n = path.length();
        while(i + 1 < n) {
            int j = i + 1;
            while(j < n && path[j] != '/') {
                j++;
            }

            string name = path.substr(i + 1, j - i - 1);
            if(name == "..") {
                if(!s.empty()) {
                    s.pop();
                }
            } else if(name == "." || name.empty()) {
                i = j;
                continue;
            } else {
                s.push(name);
            }

            i = j;
        }


        string ans;
        while(!s.empty()) {
            ans = "/" + s.top() + ans;
            s.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};