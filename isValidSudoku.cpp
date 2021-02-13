// 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];
        
        for(int i = 0;i < 9;i ++) {
            for(int j = 0;j < 9;j ++) {
                if(board[i][j] == '.') {
                    continue;
                }
                
                int r = i;
                int c = j;
                int b = r / 3 * 3  + c / 3;
                
                if(rows[r].find(board[i][j]) != rows[r].end() || cols[c].find(board[i][j]) != cols[c].end() || boxes[b].find(board[i][j]) != boxes[b].end()) {
                    return false;
                }
                
                rows[r].insert(board[i][j]);
                cols[c].insert(board[i][j]);
                boxes[b].insert(board[i][j]);
            }
        }
        
        return true;
    }
};