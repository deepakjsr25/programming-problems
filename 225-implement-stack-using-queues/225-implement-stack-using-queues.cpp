class MyStack {
public:
    /** Initialize your data structure here. */
    vector<int> v;
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        v.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(empty())
            return 0;
        
        int las = v.back();
        v.pop_back();
        return las;
    }
    
    /** Get the top element. */
    int top() {
        
        if(empty())
            return -1;
        
        return v.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(v.empty())
            return true;
        return false;    
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