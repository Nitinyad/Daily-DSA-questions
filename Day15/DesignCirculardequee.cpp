
//FIRST APPROACH  -- USING THE LIST WHICH BEHAVES LIKE THE DOUBLY LINKED LIST
class MyCircularDeque {
private:
    list<int> l;//doubly linked list 
    int size;
    int capacity;
public:
    MyCircularDeque(int k) {
        l = list<int>(k);
        size = 0;
        capacity = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;

        l.push_front(value);
        size++;
        return true;
    }   
    
    bool insertLast(int value) {
        if(isFull()) return false;
        l.push_back(value);
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        l.pop_front();
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        l.pop_back();
        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return l.front();
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return l.back();
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};


//SECOND APPRAOCH -- USING ARRAYS
class MyCircularDeque {
private:
    vector<int> queue;
    int front;
    int rear;
    int size;
    int capacity;
public:
    MyCircularDeque(int k) {
        queue = vector<int>(k);
        front = 0;
        rear = k - 1;
        size = 0;
        capacity = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        front = (front - 1 + capacity)% capacity;
        queue[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        rear = (rear + 1 ) % capacity;
        queue[rear] =value;
        size++;
        return true;    
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        front = (front + 1) % capacity;
        
        size--;
        return true;    
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        rear = (rear - 1 + capacity)%capacity;
        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return queue[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return queue[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
