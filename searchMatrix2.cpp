// 240. Search a 2D Matrix II
// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) {
            return false;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = m - 1;
        int col = 0;
        
        while(row >= 0 && col < n) {
            if(matrix[row][col] == target) {
                return true;
            }
            else if(matrix[row][col] > target) {
                row --;
            }
            else {
                col ++;
            }
        }
        
        return false;
    }
};