class MyStack {
    
    queue<int> q;
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int cnt = q.size();
        for (int i = 1 ; i < cnt; i++) {
            int ele = q.front();
            q.pop();
            q.push(ele);
        }
        
        int topele = q.front();
        q.pop();
        return topele;
        
    }
    
    /** Get the top element. */
    int top() {
        queue<int> copy = q;
        int cnt = q.size();
        for (int i = 1 ; i < cnt; i++) {
            copy.pop();
        }
        return copy.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
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