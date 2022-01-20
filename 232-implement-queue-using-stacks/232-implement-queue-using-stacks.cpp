class MyQueue {
public:
    /** Initialize your data structure here. */
    vector<int> v;
    int i;
    MyQueue() {
        i = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        v.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(empty())
            return 0;  
        return v[i++];
    }
    
    /** Get the front element. */
    int peek() {
        if(empty())
            return 0;
        return v[i]; 
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(i>=v.size())
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */