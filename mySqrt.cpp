// 69. Sqrt(x)
// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) {
            return x;
        }
        
        int l = 2;
        int h = x / 2;
        
        while(l <= h) {
            long m = l + (h - l) / 2;
            
            if(m * m == x) {
                return m;
            }
            else if(m * m < x) {
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }
        
        return h;
    }
};