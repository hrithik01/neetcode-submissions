class MinStack {
public:
    stack<int> stk;
    stack<int> stkMin;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(stkMin.empty()) {
            stkMin.push(val);
        } else {
            stkMin.push(min(val, stkMin.top()));
        }
    }
    
    void pop() {
        stk.pop();
        stkMin.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
     return stkMin.top();   
    }
};
