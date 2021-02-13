// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 0) {
            return 0;
        }
        
        int max_area = 0;
        int l = 0;
        int r = height.size() - 1;
        
        while(l < r) {
            if(height[l] < height[r]) {
                max_area = max(max_area, height[l] * (r - l));
                l ++;
            }
            else {
                max_area = max(max_area, height[r] * (r - l));
                r --;
            }
        }
        
        return max_area;
    }
};