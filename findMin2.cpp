// 154. Find Minimum in Rotated Sorted Array II
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

// iterative approach
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0) {
            return -1;
        }
        
        int l = 0;
        int r = nums.size() - 1;
        
        while(l < r) {
            int m = l + (r - l) / 2;
            
            if(nums[m] > nums[r]) {
                l = m + 1;
            }
            else if(nums[m] < nums[r]) {
                r = m;
            }
            else {
                r --;
            }
        }
        
        return nums[l];
    }
};

// recursive approach
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0) {
            return -1;
        }
        
        return findMin(nums, 0, nums.size() - 1);
    }
    
    int findMin(vector<int>& nums, int l, int r) {
        if(l == r || nums[l] < nums[r]) {
            return nums[l];
        }
        
        int m = l + (r - l) / 2;
        
        return min(findMin(nums, l, m), findMin(nums, m + 1, r));
    }
};