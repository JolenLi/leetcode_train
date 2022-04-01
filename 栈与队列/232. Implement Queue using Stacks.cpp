class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        in.push(x);
    }
    void in2out(){
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
    }
    int pop() {
        if(out.empty())
            in2out();
        int ans = out.top();
        out.pop();
        return ans;
    }

    int peek() {
        if(out.empty())
            in2out();
        return out.top();
    }

    bool empty() {
        return in.empty()&&out.empty();
    }
private:
    stack<int> in,out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */