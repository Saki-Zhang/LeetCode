// 463. Island Perimeter
// https://leetcode.com/problems/island-perimeter/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        
        int perimeter = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0;i < m;i ++) {
            for(int j = 0;j < n;j ++) {
                if(grid[i][j] == 1) {
                    perimeter += (i == 0 || grid[i - 1][j] == 0) ? 1 : 0;
                    perimeter += (i == m - 1 || grid[i + 1][j] == 0) ? 1 : 0;
                    perimeter += (j == 0 || grid[i][j - 1] == 0) ? 1 : 0;
                    perimeter += (j == n - 1 || grid[i][j + 1] == 0) ? 1 : 0;
                }
            }
        }
        
        return perimeter;
    }
};