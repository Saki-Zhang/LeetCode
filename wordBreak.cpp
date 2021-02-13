// 139. Word Break
// https://leetcode.com/problems/word-break/

// recursion with memoization
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set (wordDict.begin(), wordDict.end());
        unordered_map<string, bool> word_break;
        
        return wordBreak(s, word_set, word_break);
    }
    
    bool wordBreak(string s, unordered_set<string>& word_set, unordered_map<string, bool>& word_break) {
        // return the word break result of s when it is already in the cache
        if(word_break.find(s) != word_break.end()) {
            return word_break[s];
        }
        
        // return true and add the result into the cache when s is in the word set
        if(word_set.find(s) != word_set.end()) {
            return word_break[s] = true;
        }
        
        for(int i = 1;i < s.length();i ++) {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i);
            
            if(word_set.find(s2) != word_set.end() && wordBreak(s1, word_set, word_break)) {
                return word_break[s] = true;
            }
        }
        
        return word_break[s] = false;
    }
};