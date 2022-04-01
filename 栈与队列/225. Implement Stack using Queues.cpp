//
// Created by Jolen on 2022/4/1.
//

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        int i =que.size();
        que.push(x);
        while(i--){
            que.push(que.front());
            que.pop();
        }
    }

    int pop() {
        int ans = que.front();
        que.pop();
        return ans;
    }

    int top() {
        return que.front();
    }

    bool empty() {
        return que.empty();
    }
private:
    queue<int> que;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */