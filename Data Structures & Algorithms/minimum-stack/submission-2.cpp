class MinStack {
public:
    // define and init
    stack<int> dataSt;
    stack<int> minSt;
    MinStack() {
    }
    
    void push(int val) {
        // update data
        dataSt.push(val);
        // update min if less

        if (minSt.empty() || val <= minSt.top()) { // use equal to allow duplicate
            minSt.push(val);
        }
    }
    
    void pop() {
        // update data
        int top = dataSt.top();
        dataSt.pop();

        // update min if matched minimum
        if (top == minSt.top()) {
            minSt.pop();
        }
    }
    
    int top() {
        return dataSt.top(); 
    }
    
    int getMin() {
       return minSt.top(); 
    }
};