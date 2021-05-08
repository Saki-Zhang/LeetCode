// 127. Word Ladder
// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set (wordList.begin(), wordList.end());
        
        if(word_set.find(endWord) == word_set.end()) {
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        
        int step = 1;
        
        while(!q.empty()) {
            for(int i = q.size();i > 0;i --) {
                string word = q.front();
                q.pop();
                
                for(int j = 0;j < word.length();j ++) {
                    for(char ch = 'a';ch <= 'z';ch ++) {
                        if(ch == word[j]) {
                            continue;
                        }
                        
                        string next = word;
                        next[j] = ch;
                        
                        if(next == endWord) {
                            return step + 1;
                        }
                        
                        if(word_set.find(next) != word_set.end()) {
                            q.push(next);
                            word_set.erase(next);
                        }
                    }
                }
            }
            
            step ++;
        }
        
        
        return 0;
    }
};