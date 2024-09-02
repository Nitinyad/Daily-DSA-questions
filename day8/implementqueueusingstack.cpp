class MyQueue {
public:
    stack<int>st1 ,st2;
    MyQueue() {
        
    }
    // move all elements from s1 to s2;
    // push x into s1;
    // move all of s2 to s1;
    void push(int x) {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int x = st1.top();
        st1.pop();
        return x;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};
