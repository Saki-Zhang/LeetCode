// 120. Triangle
// https://leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0) {
            return 0;
        }
        
        for(int i = 1;i < triangle.size();i ++) {
            for(int j = 0;j <= i;j ++) {
                triangle[i][j] += j == 0 ? triangle[i - 1][j] : j == i ? triangle[i - 1][j - 1] : min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
        
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};