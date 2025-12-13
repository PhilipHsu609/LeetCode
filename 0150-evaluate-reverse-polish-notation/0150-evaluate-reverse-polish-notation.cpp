class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(const auto &t : tokens) {
            if(t == "+") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a + b);
            } else if(t == "-") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a - b);
            } else if(t == "*") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a * b);
            } else if(t == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a / b);
            } else {
                s.push(stoi(t));
            }
        }
        return s.top();
    }
};