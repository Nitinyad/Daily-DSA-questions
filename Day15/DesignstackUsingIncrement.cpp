class CustomStack {
public:
    stack<int> st;
    int maxsize;

    CustomStack(int maxSize) {
        this->maxsize = maxSize;
    }

    void push(int x) {
        if (st.size() < maxsize) {
            st.push(x);
        }
    }

    int pop() {
        if (st.empty()) {
            return -1;
        }
        int ele = st.top();
        st.pop();
        return ele;
    }

    void increment(int k, int val) {
        stack<int> temp;
        vector<int> incremented;
        int count = 0;

        // Transfer elements to a vector to modify first k elements
        while (!st.empty()) {
            incremented.push_back(st.top());
            st.pop();
        }

        // Increment the bottom k elements (reversed in the vector)
        for (int i = incremented.size() - 1; i >= max(0, (int)incremented.size() - k); i--) {
            incremented[i] += val;
        }

        // Push back all elements into the stack
        for (int i = incremented.size() - 1; i >= 0; i--) {
            st.push(incremented[i]);
        }
    }
};
