// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/

// bfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0;i < m;i ++) {
            for(int j = 0;j < n;j ++) {
                if(grid[i][j] == '1') {
                    cnt ++;
                    bfs(grid, i, j, m, n);
                }
            }
        }
        
        return cnt;
    }
    
    void bfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        queue<pair<int, int>> q;
        
        q.push({i, j});
        grid[i][j] = '0';
        
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            
            int x = p.first;
            int y = p.second;
            
            if(x - 1 >= 0 && grid[x - 1][y] == '1') {
                q.push({x - 1, y});
                grid[x - 1][y] = '0';
            }
            
            if(x + 1 < m && grid[x + 1][y] == '1') {
                q.push({x + 1, y});
                grid[x + 1][y] = '0';
            }
            
            if(y - 1 >= 0 && grid[x][y - 1] == '1') {
                q.push({x, y - 1});
                grid[x][y - 1] = '0';
            }
            
            if(y + 1 < n && grid[x][y + 1] == '1') {
                q.push({x, y + 1});
                grid[x][y + 1] = '0';
            }
        }
    }
};

// dfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0;i < m;i ++) {
            for(int j = 0;j < n;j ++) {
                if(grid[i][j] == '1') {
                    cnt ++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        
        return cnt;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0';
        
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i, j - 1, m, n);
        dfs(grid, i, j + 1, m, n);
    }
};