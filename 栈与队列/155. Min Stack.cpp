class MinStack {
public:
    stack<int> stk;
    stack<int> minVal;
    MinStack() {
        minVal.push(INT_MAX);
    }

    void push(int val) {
        stk.push(val);
        minVal.push(min(minVal.top(),val));
    }

    void pop() {
        stk.pop();
        minVal.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minVal.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */