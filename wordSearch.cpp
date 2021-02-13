// 79. Word Search
// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) {
            return false;
        }
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0;i < m;i ++) {
            for(int j = 0;j < n;j ++) {
                if(exist(board, word, m, n, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word, int m, int n, int i, int j, int p) {
        if(p >= word.length()) {
            return true;
        }
        
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[p]) {
            return false;
        }
        
        board[i][j] = '#'; // mark as visited
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        for(int k = 0;k < 4;k ++) {
            if(exist(board, word, m, n, i + dx[k], j + dy[k], p + 1)) {
                return true;
            }
        }
        
        board[i][j] = word[p];
        
        return false;
    }
};