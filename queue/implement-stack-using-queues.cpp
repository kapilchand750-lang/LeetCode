class MyStack {
    stack <int> stk;
public:
    MyStack() {
    }
    
    void push(int x) {
        stk.push(x);
    }
    
    int pop() {
        if (stk.empty()) {
            throw runtime_error("Stack is empty, cannot pop!");
        }
        int d = stk.top();
        stk.pop();
        return d;
    }
    
    int top() {
        if (stk.empty()) {
            throw runtime_error("Stack is empty, cannot pop!");
        }
        return stk.top();
    }
    
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */