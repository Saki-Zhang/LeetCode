// 716. Max Stack
// https://leetcode.com/problems/max-stack/

class MaxStack {
private:
    stack<int> s1;
    stack<int> s2;

public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty() || s2.top() <= x) {
            s2.push(x);
        }
    }
    
    int pop() {
        if(s1.empty() || s2.empty()) {
            return -1;
        }
        
        int x = s1.top();
        s1.pop();
        if(s2.top() == x) {
            s2.pop();
        }
        
        return x;
    }
    
    int top() {
        return s1.empty() ? -1 : s1.top();
    }
    
    int peekMax() {
        return s2.empty() ? -1 : s2.top();
    }
    
    int popMax() {
        if(s1.empty() || s2.empty()) {
            return -1;
        }
        
        int x = s2.top();
        s2.pop();
        
        stack<int> buf;
        
        while(!s1.empty() && s1.top() != x) {
            buf.push(s1.top());
            s1.pop();
        }
        
        s1.pop();
        
        while(!buf.empty()) {
            push(buf.top());
            buf.pop();
        }
        
        return x;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */