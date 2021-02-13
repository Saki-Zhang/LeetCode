// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/

// dynamic programming - space complexity: O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        int n = s.length();
        
        vector<vector<int>> dp (n, vector<int> (n, 0)); // dp[i][j] == 1 if substr(i, j) is a palindrome
        
        // length of substr = 1
        for(int i = 0;i < n;i ++) {
            if(result.length() < 1) {
                result = s.substr(i, 1);
            }
            dp[i][i] = 1;
        }
        
        // length of substr = 2
        for(int i = 0;i < n - 1;i ++) {
            if(s[i] == s[i + 1]) {
                if(result.length() < 2) {
                    result = s.substr(i, 2);
                }
                dp[i][i + 1] = 1;
            }
        }
        
        // 3 <= length of substr <= n
        for(int len = 3;len <= n;len ++) {
            for(int i = 0;i + len - 1 < n;i ++) {
                int l = i;
                int r = i + len - 1;
                
                if(s[l] == s[r] && dp[l + 1][r - 1] == 1) {
                    if(result.length() < len) {
                        result = s.substr(l, len);
                    }
                    dp[l][r] = 1;
                }
            }
        }
        
        return result;
    }
};

// expand around center - space complexity: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        
        // iterate through all possible centers
        for(int i = 0;i < s.length();i ++) {
            expand(s, i, i, result);
            expand(s, i, i + 1, result);
        }
        
        return result;
    }
    
    void expand(string s, int l, int r, string& result) {
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            if(result.length() < r - l + 1) {
                result = s.substr(l, r - l + 1);
            }
            
            l --;
            r ++;
        }
    }
};