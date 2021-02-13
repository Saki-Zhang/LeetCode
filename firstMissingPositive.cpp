// 41. First Missing Positive
// https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int min_value = 1;
        int max_value = nums.size();
        
        // place the numbers in the range from 1 to n at their correct positions in O(n) time
        for(int i = 0;i < nums.size();i ++) {
            while(nums[i] >= min_value && nums[i] <= max_value && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for(int i = 0;i < nums.size();i ++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return max_value + 1;
    }
};