/**
 * 232. 用栈实现队列
 * https://leetcode-cn.com/problems/implement-queue-using-stacks/
 */

class MyQueue {
public:
    stack<int> inStack;
    stack<int> outStack;

    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp;
        if(!outStack.empty()) {
            tmp = outStack.top();
            outStack.pop();
            return tmp;
        } 

        while(!inStack.empty()) {
            tmp = inStack.top();
            outStack.push(tmp);
            inStack.pop();
        }

        tmp = outStack.top();
        outStack.pop();
        return tmp;

    }
    
    /** Get the front element. */
    int peek() {
        int tmp;
        if(!outStack.empty()) {
            return outStack.top();
        } 

        while(!inStack.empty()) {
            tmp = inStack.top();
            outStack.push(tmp);
            inStack.pop();
        }

        return outStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */