class MinStack {
private:
    stack<int> normalStack;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        normalStack.push(x);
        
        int currMin = minStack.empty() ? INT_MAX : minStack.top();
        if (x <= currMin) minStack.push(x);
    }
    
    void pop() {
        int removed = normalStack.top();
        normalStack.pop();
        
        if (removed == minStack.top())
            minStack.pop();
    }
    
    int top() {
        return normalStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */