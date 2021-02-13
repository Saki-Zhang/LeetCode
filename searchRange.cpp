// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findStartingIndex(nums, target);
        int last = findEndingIndex(nums, target);
        
        return {first, last};
    }
    
    int findStartingIndex(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return -1;
        }
        
        int index = -1;
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r) {
            int m = l + (r - l) / 2;
            
            if(nums[m] == target) {
                index = m;
            }
            
            if(nums[m] < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        
        return index;
    }
    
    int findEndingIndex(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return -1;
        }
        
        int index = -1;
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r) {
            int m = l + (r - l) / 2;
            
            if(nums[m] == target) {
                index = m;
            }
            
            if(nums[m] <= target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        
        return index;
    }
};