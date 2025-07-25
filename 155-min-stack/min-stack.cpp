class MinStack {
public:
    stack<int> stk;
    int m = INT_MAX;
    MinStack() {
    }
    
    void push(int val) {
        if(val <= m){
            stk.push(m);
            m = val;
        }
        stk.push(val);
    }
    
    void pop() {
        int temp = stk.top();
        stk.pop();
        if(temp == m){
            m = stk.top();
            stk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        //return stk
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */