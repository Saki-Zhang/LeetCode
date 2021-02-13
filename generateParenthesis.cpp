// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesis(n, 0, 0, "", result);
        return result;
    }
    
    void generateParenthesis(int n, int open, int close, string curr, vector<string>& result) {
        if(curr.size() == n * 2) {
            result.push_back(curr);
            return;
        }
        
        if(open < n) {
            generateParenthesis(n, open + 1, close, curr + "(", result);
        }
        if(close < open) {
            generateParenthesis(n, open, close + 1, curr + ")", result);
        }
    }
};