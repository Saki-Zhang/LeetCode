// 367. Valid Perfect Square
// https://leetcode.com/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0 || num == 1) {
            return true;
        }
        
        int l = 2;
        int h = num / 2;
        
        while(l <= h) {
            long m = l + (h - l) / 2;
            
            if(m * m == num) {
                return true;
            }
            else if(m * m < num) {
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }
        
        return false;
    }
};