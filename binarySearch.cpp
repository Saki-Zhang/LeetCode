// 704. Binary Search
// https://leetcode.com/problems/binary-search/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return -1;
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
        
        return -1;
    }
};