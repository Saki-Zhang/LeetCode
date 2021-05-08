// 126. Word Ladder II
// https://leetcode.com/problems/word-ladder-ii/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set (wordList.begin(), wordList.end());
        
        if(word_set.find(endWord) == word_set.end()) {
            return {};
        }
        
        vector<vector<string>> result;
        
        unordered_map<string, int> step; // the minimum number of steps taken to transform into a word
        step[beginWord] = 1;
        
        queue<vector<string>> q;
        q.push({beginWord});
        
        while(!q.empty()) {
            for(int i = q.size();i > 0;i --) {
                vector<string> path = q.front();
                string word = path.back();
                q.pop();
                
                for(int j = 0;j < word.length();j ++) {
                    for(char ch = 'a';ch <= 'z';ch ++) {
                        if(ch == word[j]) {
                            continue;
                        }
                        
                        string next = word;
                        next[j] = ch;
                        
                        if(word_set.find(next) == word_set.end()) {
                            continue;
                        }
                        
                        if(step.find(next) != step.end() && step[next] <= path.size()) { // the next word could be transformed into using less steps
                            continue;
                        }
                        
                        path.push_back(next);
                        step[next] = path.size();
                        
                        if(next == endWord) {
                            result.push_back(path);
                        }
                        
                        q.push(path);
                        path.pop_back();
                    }
                }
            }
            
            if(result.size() > 0) {
                return result;
            }
        }
        
        return {};
    }
};