/*
Intuition: To use the 2 stacks to track for min and current content

Approach:
    2 stack, dataSt and minSt
    1. push
        dataSt.push
        minSt push if val is less than minSt.top()
        since stack is LIFO, then we ensure st.top() min and st.back() max (reverse order)
    
    2. pop
        dataSt.pop
        minSt pop if dataSt.top (to top) is == minSt top (update the value)
    
    3. top
        dataSt.top
    
    4. getMin
        minSt.top
*/
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
