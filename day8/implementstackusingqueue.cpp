//USING TWO QUEUES 
class MyStack {
public:
    queue<int>q1 , q2;  
    MyStack() {
    }
    
    void push(int x) {
        // add into the q2;
        q2.push(x);
        // move all element of q1 to q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        // swaping the q1 and q2 because the final stack is into the q1;
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};



// USING SINGLE QUEUE
class MyStack {
private:
//using single queue
        queue<int>q1;
public:
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
        for(int i = 0; i < q1.size() -1 ;i++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

