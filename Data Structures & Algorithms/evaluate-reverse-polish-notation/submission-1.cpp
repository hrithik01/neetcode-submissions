class Solution {
public:
    bool isOp(string s) {
        return s=="+" || s=="-" || s=="*" || s=="/";
    }
    int eval(int a, int b, string op) {
        if(op == "+") return a + b;
        else if(op == "-") return a - b;
        else if (op == "*") return a*b;
        else return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int ans = 0;
        for(int i=0; i<tokens.size(); i++) {
            if(isOp(tokens[i])) {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                int curr = eval(a, b, tokens[i]);
                stk.push(curr);
            } else {
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};
