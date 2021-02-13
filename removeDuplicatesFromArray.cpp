// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        
        for(;j < nums.size();j ++) {
            if(j == 0 || nums[j] != nums[j - 1]) {
                nums[i ++] = nums[j];
            }
        }
        
        return i;
    }
};