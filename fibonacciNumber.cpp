// 509. Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int fib(int n) {
        if(n <= 1) {
            return n;
        }
        
        int f1 = 0;
        int f2 = 1;
        
        for(int i = 2;i <= n;i ++) {
            int f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        
        return f2;
    }
};