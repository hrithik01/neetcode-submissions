class Solution {
public:
    bool isOp(string s) {
        return s=="+" || s=="-" || s=="*" || s=="/";
    }
    int eval(string as, string bs, string op) {
        int a = stoi(as), b = stoi(bs);
        if(op == "+") return a + b;
        else if(op == "-") return a - b;
        else if (op == "*") return a*b;
        else return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        int ans = 0;
        for(int i=0; i<tokens.size(); i++) {
            if(isOp(tokens[i])) {
                string bs = stk.top();
                stk.pop();
                string as = stk.top();
                stk.pop();
                int curr = eval(as, bs, tokens[i]);
                stk.push(to_string(curr));
            } else {
                stk.push(tokens[i]);
            }
        }
        return stoi(stk.top());
    }
};
