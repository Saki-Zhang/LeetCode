// 35. Search Insert Position
// https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r) {
            int m = l + (r - l) / 2;
            
            if(nums[m] == target) {
                return m;
            }
            else if(nums[m] < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        
        return l;
    }
};