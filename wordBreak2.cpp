// 140. Word Break II
// https://leetcode.com/problems/word-break-ii/

// recursion with memoization
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set (wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> word_break;
        
        return wordBreak(s, word_set, word_break);
    }
    
    vector<string> wordBreak(string s, unordered_set<string>& word_set, unordered_map<string, vector<string>>& word_break) {
        if(word_break.find(s) != word_break.end()) {
            return word_break[s];
        }
        
        vector<string> result;
        
        if(word_set.find(s) != word_set.end()) {
            result.push_back(s);
        }
        
        for(int i = 1;i < s.length();i ++) {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i);
            
            if(word_set.find(s2) != word_set.end()) {
                for(string wb : wordBreak(s1, word_set, word_break)) {
                    result.push_back(wb + " " + s2);
                }
            }
        }
        
        return word_break[s] = result;
    }
};