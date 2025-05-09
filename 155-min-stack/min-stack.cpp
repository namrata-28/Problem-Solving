class MinStack {
private:
    stack<int> stack, minStack;  

public:
    MinStack() {}  

    void push(int x) {
        stack.push(x); 
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x); 
    }

    void pop() {
        if (stack.top() == minStack.top())
            minStack.pop();  
                             
        stack.pop();         
    }

    int top() {
        return stack.top();  
    }

    int getMin() {
        return minStack.top();  
                                
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