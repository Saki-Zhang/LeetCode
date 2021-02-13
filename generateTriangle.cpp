// 118. Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> prev_row;
        
        for(int i = 1;i <= numRows;i ++) {
            vector<int> curr_row;
            
            for(int j = 0;j < i;j ++) {
                curr_row.push_back((j == 0 || j == i - 1) ? 1 : prev_row[j - 1] + prev_row[j]);
            }
            
            result.push_back(curr_row);
            prev_row = curr_row;
        }
        
        return result;
    }
};