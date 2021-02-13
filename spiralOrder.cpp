// 54. Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) {
            return {};
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> result;
        vector<vector<int>> visited (m, vector<int> (n, 0));
        
        int d = 0;
        int x = 0;
        int y = 0;
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        for(int i = 0;i < m * n;i ++) {
            // add the current value to the result and mark the current position as visited
            result.push_back(matrix[x][y]);
            visited[x][y] = 1;
            
            // try to move to the next position on the current direction
            x += dx[d];
            y += dy[d];
            
            if(x >= 0 && x < m && y >= 0 && y < n && visited[x][y] == 0) { // the next position is valid
                continue;
            }
            else { // the next position is not valid
                // move back to the current position
                x -= dx[d];
                y -= dy[d];
                
                // change the direction
                d += 1;
                d %= 4;
                
                // move to the next position
                x += dx[d];
                y += dy[d];
            }
        }
        
        return result;
    }
};