// 694. Number of Distinct Islands
// https://leetcode.com/problems/number-of-distinct-islands/

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        
        unordered_set<string> shapes;
        
        for(int i = 0;i < m;i ++) {
            for(int j = 0;j < n;j ++) {
                if(grid[i][j] == 1) {
                    string path = "";
                    dfs(grid, i, j, m, n, '#', path);
                    shapes.insert(path);
                }
            }
        }
        
        return shapes.size();
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, char d, string& path) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }
        
        grid[i][j] = 0;
        path += d; // add the direction to the path string to form the shape of the island
        
        dfs(grid, i - 1, j, m, n, '0', path);
        dfs(grid, i + 1, j, m, n, '1', path);
        dfs(grid, i, j - 1, m, n, '2', path);
        dfs(grid, i, j + 1, m, n, '3', path);
        
        path += '#'; // add the exit mark
    }
};