/**
 * 225. 用队列实现栈
 * https://leetcode-cn.com/problems/implement-stack-using-queues/
 */

class MyStack {
public:
    queue<int> Q;
    queue<int> tmpQueue;

    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while(!Q.empty()) {
            tmpQueue.push(Q.front());
            Q.pop();
        }
        Q.push(x);
        while(!tmpQueue.empty()) {
            Q.push(tmpQueue.front());
            tmpQueue.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp = Q.front();
        Q.pop();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        return Q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */