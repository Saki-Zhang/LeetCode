// 162. Find Peak Element
// https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 0) {
            return -1;
        }
        
        int l = 0;
        int r = nums.size() - 1;
        
        while(l < r) {
            int m = l + (r - l) / 2;
            
            if(nums[m] < nums[m + 1]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        
        return l;
    }
};