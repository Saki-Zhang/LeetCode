// 81. Search in Rotated Sorted Array II
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return false;
        }
        
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r) {
            int m = l + (r - l) / 2;
            
            if(nums[m] == target) {
                return true;
            }
            else if(nums[m] > nums[l]) {
                if(target >= nums[l] && target < nums[m]) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            else if(nums[m] < nums[l]) {
                if(target > nums[m] && target <= nums[r]) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            else {
                l ++;
            }
        }
        
        return false;
    }
};