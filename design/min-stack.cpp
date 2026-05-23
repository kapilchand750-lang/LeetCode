#include<bits/stdc++.h>
class MinStack {
public:
    stack <int> stk;
    stack <int> minstack;
    MinStack() {   
    }
    
    void push(int val) {
        if(minstack.empty() || val<=minstack.top()) minstack.push(val);
        stk.push(val);
    }
    
    void pop() {
        if(minstack.top() == stk.top()) minstack.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstack.top();
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