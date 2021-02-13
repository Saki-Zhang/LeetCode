// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

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
            else if(nums[m] >= nums[l]) { // the left subarray is sorted (not rotated)
                if(target >= nums[l] && target < nums[m]) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            else { // the right subarray is sorted (not rotated)
                if(target > nums[m] && target <= nums[r]) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
        }
        
        return -1;
    }
};