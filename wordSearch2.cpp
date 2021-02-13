// 212. Word Search II
// https://leetcode.com/problems/word-search-ii/

class TrieNode {
public:
    TrieNode* next[26];
    string word;

public:
    TrieNode() {
        memset(next, NULL, sizeof(next));
        word = "";
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.size() == 0) {
            return {};
        }
        
        vector<string> result;
        
        // build the trie (prefix tree)
        TrieNode* root = new TrieNode();
        
        for(string word : words) {
            TrieNode* curr = root;
            
            for(char ch : word) {
                if(curr -> next[ch - 'a'] == NULL) {
                    curr -> next[ch - 'a'] = new TrieNode();
                }
                curr = curr -> next[ch - 'a'];
            }
            
            curr -> word = word;
        }
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0;i < m;i ++) {
            for(int j = 0;j < n;j ++) {
                findWords(board, root, m, n, i, j, result);
            }
        }
        
        return result;
    }
    
    void findWords(vector<vector<char>>& board, TrieNode* tnode, int m, int n, int i, int j, vector<string>& result) {
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#') {
            return;
        }
        
        char ch = board[i][j];
        tnode = tnode -> next[ch - 'a'];
        
        if(tnode == NULL) {
            return;
        }
        
        if(tnode -> word != "") {
            result.push_back(tnode -> word);
            tnode -> word = ""; // delete the word from the trie as it has been found
        }
        
        board[i][j] = '#'; // mark as visited
        
        findWords(board, tnode, m, n, i, j + 1, result);
        findWords(board, tnode, m, n, i + 1, j, result);
        findWords(board, tnode, m, n, i, j - 1, result);
        findWords(board, tnode, m, n, i - 1, j, result);
        
        board[i][j] = ch;
    }
};