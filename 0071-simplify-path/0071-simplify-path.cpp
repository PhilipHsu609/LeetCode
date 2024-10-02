class Solution {
public:
    string simplifyPath(string path) {
        vector<string> sp;
        int pos = 0;
        if(path[path.length() - 1] != '/') path += '/';
        for(int i = 1; i < path.length(); i++) {
            if(path[i] == '/') {
                string sub = path.substr(pos + 1, i - pos - 1);
                if(sub != "" && sub != ".") {
                    sp.push_back(sub);
                    // cout << sub << endl;
                }
                pos = i;
            }
        }
        
        string ans = "";
        stack<string> s;
        for(int i = 0; i < sp.size(); i++) {
            if(sp[i] == "..") {
                if(!s.empty())
                    s.pop();
            }else {
                s.push(sp[i]);
            }
        }
        
        if(s.empty()) return "/";
        
        while(!s.empty()) {
            ans = "/" + s.top() + ans;
            s.pop();
        }
        
        return ans;
    }
};