// 498. Diagonal Traverse
// https://leetcode.com/problems/diagonal-traverse/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) {
            return {};
        }
        
        vector<int> result;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int k = 0;k < m + n - 1;k ++) {
            // k = i + j
            // 0 <= i <= m - 1
            // 0 <= j <= n - 1
            
            int start = k % 2 == 0 ? min(k, m - 1) : max(0, k - n + 1);
            int end = k % 2 == 0 ? max(0, k - n + 1) : min(k, m - 1);
            int dir = k % 2 == 0 ? -1 : 1;
            
            for(int i = start;;i += dir) {
                int j = k - i;
                result.push_back(matrix[i][j]);
                
                if(i == end) {
                    break;
                }
            }
        }
        
        return result;
    }
};