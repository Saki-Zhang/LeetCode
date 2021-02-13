// 155. Min Stack
// https://leetcode.com/problems/min-stack/

class MinStack {
private:
    stack<int> s1;
    stack<int> s2;

public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty() || s2.top() >= x) {
            s2.push(x);
        }
    }
    
    void pop() {
        if(s1.empty() || s2.empty()) {
            return;
        }
        
        if(s1.top() == s2.top()) {
            s2.pop();
        }
        s1.pop();
    }
    
    int top() {
        return s1.empty() ? -1 : s1.top();
    }
    
    int getMin() {
        return s2.empty() ? -1 : s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */