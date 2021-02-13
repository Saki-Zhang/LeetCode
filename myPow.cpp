// 50. Pow(x, n)
// https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        long N = n; // corner case: n = INT_MIN
        
        if(N < 0) {
            return 1 / fastPow(x, -N);
        }
        else {
            return fastPow(x, N);
        }
    }
    
    double fastPow(double x, long n) {
        if(n == 0) {
            return 1;
        }
        
        double y = fastPow(x, n / 2);
        
        if(n % 2 == 0) {
            return y * y;
        }
        else {
            return y * y * x;
        }
    }
};