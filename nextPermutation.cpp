// 31. Next Permutation
// https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0) {
            return;
        }
        
        // find the starting position i of the decreasing sequence
        int i = nums.size() - 1;
        while(i > 0 && nums[i - 1] >= nums[i]) {
            i --;
        }
        
        // swap nums[i - 1] with the next greater element in the decreasing sequence
        if(i > 0) {
            int j = nums.size() - 1;
            while(nums[j] <= nums[i - 1]) {
                j --;
            }
            
            swap(nums[i - 1], nums[j]);
        }
        
        // reverse the decreasing sequence
        reverse(nums.begin() + i, nums.end());
    }
};