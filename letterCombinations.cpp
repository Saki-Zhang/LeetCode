// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string curr = "";
        
        unordered_map<char, string> letters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        combine(digits, 0, curr, letters, result);
        
        return result;
    }
    
    void combine(string digits, int start, string& curr, unordered_map<char, string>& letters, vector<string>& result) {
        if(start == digits.size()) {
            if(curr != "") {
                result.push_back(curr);
            }
            return;
        }
        
        for(char ch : letters[digits[start]]) {
            curr.push_back(ch);
            combine(digits, start + 1, curr, letters, result);
            curr.pop_back();
        }
    }
};