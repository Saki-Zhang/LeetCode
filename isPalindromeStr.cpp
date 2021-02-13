// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0) {
            return true;
        }
        
        int l = 0;
        int r = s.length() - 1;
        
        while(l < r) {
            if(!isalnum(s[l])) {
                l ++;
                continue;
            }
            
            if(!isalnum(s[r])) {
                r --;
                continue;
            }
            
            if(tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            
            l ++;
            r --;
        }
        
        return true;
    }
};