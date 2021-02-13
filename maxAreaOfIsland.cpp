// 695. Max Area of Island
// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        
        int max_area = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0;i < m;i ++) {
            for(int j = 0;j < n;j ++) {
                if(grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid, i, j, m, n, area);
                    max_area = max(max_area, area);
                }
            }
        }
        
        return max_area;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int& area) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }
        
        grid[i][j] = 0;
        area ++;
        
        dfs(grid, i - 1, j, m, n, area);
        dfs(grid, i + 1, j, m, n, area);
        dfs(grid, i, j - 1, m, n, area);
        dfs(grid, i, j + 1, m, n, area);
    }
};